#include "MultiplyFilter.h"

MultiplyFilter::MultiplyFilter(const std::shared_ptr<Filter>& multiplier, const std::shared_ptr<Filter>& multiplicand)
	: myMultiplier(multiplier)
	, myMultiplicand(multiplicand)
{
}

MultiplyFilter::~MultiplyFilter()
{
}

std::shared_ptr<Picture> MultiplyFilter::ApplyImpl(const std::shared_ptr<Picture>& pic)
{
	auto a = myMultiplier->Apply(pic)->Mat();
	auto b = myMultiplicand->Apply(pic)->Mat();

	cv::Mat channels[3];
	a.convertTo(a, CV_64F);
	cv::split(a, channels);
	for (int i = 0; i < 3; i++)
		cv::multiply(channels[i], b, channels[i]);;
	
	cv::Mat out;
	merge(channels, 3, out);
	out.convertTo(out, CV_8U);
	
	return std::make_shared<Picture>(out);
}
