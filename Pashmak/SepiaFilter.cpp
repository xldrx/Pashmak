#include "SepiaFilter.h"

SepiaFilter::SepiaFilter()
{
	SepiaKernel = (cv::Mat_<float>(4, 3) << \
		0.200, 0.169, 0.593, \
		0.268, 0.086, 0.949, \
		0.231, 0.134, 0.972, \
		0.000, 0.000, 0.000);
}

SepiaFilter::~SepiaFilter()
{
}

std::shared_ptr<Picture> SepiaFilter::ApplyImpl(const std::shared_ptr<Picture>& pic)
{
	cv::Mat src = pic->Mat();
	cv::Mat res(src.size(), src.type());
	transform(src, res, SepiaKernel);
	return std::make_shared<Picture>(res);
}