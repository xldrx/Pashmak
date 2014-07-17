#pragma once
#include "Filter.h"

class NoOpFilter :
	public Filter
{
public:
	NoOpFilter();
	~NoOpFilter();

private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& media) override;
};

