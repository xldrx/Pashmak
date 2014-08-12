#include "HardTransition.h"

HardTransition::HardTransition()
{
}

HardTransition::~HardTransition()
{
}

std::shared_ptr<Picture> HardTransition::Transit(const std::shared_ptr<Picture>& a, const std::shared_ptr<Picture>& b, float time)
{
	return time < 0.5 ? a : b;
}
