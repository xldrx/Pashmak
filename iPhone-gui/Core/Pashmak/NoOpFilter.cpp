#include "NoOpFilter.h"

NoOpFilter::NoOpFilter()
{
}

NoOpFilter::~NoOpFilter()
{
}

std::shared_ptr<Picture> NoOpFilter::ApplyImpl(const std::shared_ptr<Picture>& media)
{
	return media;
}
