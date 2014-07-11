#include "PictureFilter.h"

PictureFilter::PictureFilter()
{
}

PictureFilter::~PictureFilter()
{
}

std::shared_ptr<Media> PictureFilter::Apply(const std::shared_ptr<Media>& media)
{
	return ApplyImpl(std::static_pointer_cast<Picture>(media));
}
