#pragma once
#include "Transition.h"

class FadingTransition :
	public Transition
{
public:
	FadingTransition();
	~FadingTransition();

	std::shared_ptr<Picture> Transit(const std::shared_ptr<Picture>& a, const std::shared_ptr<Picture>& b, float time) override;
};

