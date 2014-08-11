#include "FadingTransition.h"

FadingTransition::FadingTransition()
{
}

FadingTransition::~FadingTransition()
{
}

std::shared_ptr<Picture> FadingTransition::Transit(const std::shared_ptr<Picture>& a, const std::shared_ptr<Picture>& b, float time)
{
	cv::Mat out;
	cv::addWeighted(a->Mat(), time, b->Mat(), 1.0 - time, 0.0, out);
	return std::make_shared<Picture>(out);
}
