#include "GaussianNoiseFilter.h"

GaussianNoiseFilter::GaussianNoiseFilter(int mean, int stddev)
	: Mean(mean)
	, StdDev(stddev)
{
}

GaussianNoiseFilter::~GaussianNoiseFilter()
{
}

std::shared_ptr<Picture> GaussianNoiseFilter::ApplyImpl(const std::shared_ptr<Picture>& pic)
{
	const auto& src = pic->Mat();
	cv::Mat res;
	res.create(src.size(), src.type());
	randn(res, Mean, StdDev);
	res += src;
	return std::make_shared<Picture>(res);
}