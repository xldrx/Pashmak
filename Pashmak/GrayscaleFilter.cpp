#include "GrayscaleFilter.h"
#include <opencv2/imgproc/imgproc.hpp>

GrayscaleFilter::GrayscaleFilter()
{
}

GrayscaleFilter::~GrayscaleFilter()
{
}

std::shared_ptr<Picture> GrayscaleFilter::ApplyImpl(const std::shared_ptr<Picture>& pic)
{
	cv::Mat src = pic->Mat();
	cv::Mat res(src.size(), src.type());
	cv::cvtColor(src, res, CV_BGR2GRAY);
	return std::make_shared<Picture>(res);
}