#pragma once
#include "Filter.h"

class NoOpFilter :
	public Filter
{
public:
	NoOpFilter();
	~NoOpFilter();

	std::shared_ptr<Media> Apply(const std::shared_ptr<Media>& media) override;
};

