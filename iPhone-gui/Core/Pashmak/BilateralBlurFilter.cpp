#include "BilateralBlurFilter.h"

BilateralBlurFilter::BilateralBlurFilter(int dia, double sigmaC, double sigmaS)
	: Diameter(dia)
	, SigmaColor(sigmaC)
	, SigmaSpace(sigmaS)
{
}

BilateralBlurFilter::~BilateralBlurFilter()
{
}

std::shared_ptr<Picture> BilateralBlurFilter::ApplyImpl(const std::shared_ptr<Picture>& pic)
{
	const auto& src = pic->Mat();
    cv::Mat res;
    cv::bilateralFilter(src, res, Diameter, SigmaColor, SigmaSpace);
    return std::make_shared<Picture>(res);
}