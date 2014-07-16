#pragma once
#include "PictureFilter.h"

class MultiplyFilter :
	public Filter
{
private:
	std::shared_ptr<Filter> myMultiplier;
	std::shared_ptr<Filter> myMultiplicand;

public:
	MultiplyFilter(const std::shared_ptr<Filter>& multiplier, const std::shared_ptr<Filter>& multiplicand);
	~MultiplyFilter();

	std::shared_ptr<Media> Apply(const std::shared_ptr<Media>& pic) override;
};

