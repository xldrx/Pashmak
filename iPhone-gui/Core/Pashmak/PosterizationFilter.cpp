#include "PosterizationFilter.h"
#include <opencv2/imgproc/imgproc.hpp>

PosterizationFilter::PosterizationFilter()
{
}

PosterizationFilter::~PosterizationFilter()
{
}

std::shared_ptr<Picture> PosterizationFilter::ApplyImpl(const std::shared_ptr<Picture>& pic)
{
	cv::Mat src = pic->Mat();
	cv::Mat res(src.size(), src.type());
	cv::threshold(src, res, 125, 255, cv::THRESH_BINARY);
	return std::make_shared<Picture>(res);
}