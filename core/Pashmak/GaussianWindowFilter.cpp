#include "GaussianWindowFilter.h"
#include <opencv2/core/core_c.h>

using namespace cv;

namespace
{
	Mat getGaussianDist(Size s)
	{
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

				res.at<double>(i, j) = exp (- (A / B + C / D));
			}
		}
		
		normalize(res, res, 0, 1, CV_MINMAX);
		return res;
	}
}

GaussianWindowFilter::GaussianWindowFilter()
{
}

GaussianWindowFilter::~GaussianWindowFilter()
{
}

std::shared_ptr<Picture> GaussianWindowFilter::ApplyImpl(const std::shared_ptr<Picture>& pic)
{
	Mat src = pic->Mat();
	Mat res(src.size(), src.type());
	Mat channel[3];
	Mat buff;
	src.convertTo(buff, CV_64FC3);
	split(buff, channel);

	Mat a = getGaussianDist(src.size());
	multiply(channel[0], a, channel[0]);
	multiply(channel[1], a, channel[1]);
	multiply(channel[2], a, channel[2]);
	merge(channel, 3, buff);

	return std::make_shared<Picture>(buff);
}

