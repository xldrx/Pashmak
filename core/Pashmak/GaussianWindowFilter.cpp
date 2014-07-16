#include "GaussianWindowFilter.h"
#include "MultiplyFilter.h"
#include <opencv2/core/core_c.h>

using namespace cv;

namespace
{
	class GaussianDistFilter
		: public PictureFilter
	{
	public:
		GaussianDistFilter() {}
		~GaussianDistFilter() {}

	private:
		std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic)
		{
			auto s = pic->Mat().size();

			// Vertical standard deviation
			double sigmaX = s.height / 2;
			// Horizantal standard deviation
			double sigmaY = s.width / 2;
			// Center point of the window
			Point center(s.height / 2, s.width / 2);

			Mat res = Mat::zeros(s, CV_64F);
			for (int i = 0; i < s.height; i++)
			{
				for (int j = 0; j < s.width; j++)
				{
					double A = (i - center.x) * (i - center.x);
					double B = (2 * sigmaX * sigmaX);
					double C = (j - center.y) * (j - center.y);
					double D = (2 * sigmaY * sigmaY);

					res.at<double>(i, j) = exp(-(A / B + C / D));
				}
			}

			normalize(res, res, 0, 1, CV_MINMAX);
			return std::make_shared<Picture>(res);
		}
	};
}

GaussianWindowFilter::GaussianWindowFilter()
{
}

GaussianWindowFilter::~GaussianWindowFilter()
{
}

std::shared_ptr<Picture> GaussianWindowFilter::ApplyImpl(const std::shared_ptr<Picture>& pic)
{
	MultiplyFilter filter(std::make_shared<NoOpFilter>(), std::make_shared<GaussianDistFilter>());
	return std::static_pointer_cast<Picture>(filter.Apply(pic));
}

