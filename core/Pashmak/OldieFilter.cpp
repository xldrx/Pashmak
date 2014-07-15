#include "OldieFilter.h"
#include <time.h>

using namespace std;
using namespace cv;

OldieFilter::OldieFilter(unsigned int lineNumber)
	: LineNumber(lineNumber)
{
}

OldieFilter::~OldieFilter()
{
}

std::shared_ptr<Picture> OldieFilter::ApplyImpl(const std::shared_ptr<Picture>& pic)
{
	const auto& src = pic->Mat();

	int a, b, c;
	cv::Mat res;
	res = cv::Mat::zeros(src.size(), src.type());
	srand((unsigned)time(0));
	for (unsigned int i = 0; i < LineNumber; i++) 
	{
		a = rand() % src.size().height;
		b = rand() % src.size().height;
		c = rand() % src.size().width - 1;

		res(Range(min(a, b), max(a, b)), Range(c, c + 1)) = Scalar(32, 32, 32);
	}

	c = rand() % src.size().width - 1;
	res(Range(0, res.size().height), Range(c, c + 1)) = Scalar(32, 32, 32);
	c = rand() % src.size().width - 1;
	res(Range(0, res.size().height), Range(c, c + 1)) = Scalar(32, 32, 32);
	res += src;

	return std::make_shared<Picture>(res);
}
