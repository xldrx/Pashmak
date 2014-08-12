#pragma once
#include "Transition.h"
class HardTransition :
	public Transition
{
public:
	HardTransition();
	~HardTransition();

	std::shared_ptr<Picture> Transit(const std::shared_ptr<Picture>& a, const std::shared_ptr<Picture>& b, float time) override;
};

