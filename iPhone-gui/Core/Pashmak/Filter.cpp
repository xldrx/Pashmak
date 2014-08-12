#include "Filter.h"

Filter::Filter()
{
}

Filter::~Filter()
{
}

std::shared_ptr<Picture> Filter::Apply(const std::shared_ptr<Picture>& media)
{
	return ApplyImpl(std::static_pointer_cast<Picture>(media));
}
