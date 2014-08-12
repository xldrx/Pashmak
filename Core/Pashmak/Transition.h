#pragma once
#include "Picture.h"

class Transition
{
public:
	Transition();
	~Transition();

	virtual std::shared_ptr<Picture> Transit(const std::shared_ptr<Picture>& a, const std::shared_ptr<Picture>& b, float time) = 0;
};

