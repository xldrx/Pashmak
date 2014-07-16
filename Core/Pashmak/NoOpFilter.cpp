#include "NoOpFilter.h"

NoOpFilter::NoOpFilter()
{
}

NoOpFilter::~NoOpFilter()
{
}

std::shared_ptr<Media> NoOpFilter::Apply(const std::shared_ptr<Media>& media)
{
	return media;
}
