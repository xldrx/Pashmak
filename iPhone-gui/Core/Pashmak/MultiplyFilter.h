#pragma once
#include "Filter.h"

class MultiplyFilter :
	public Filter
{
private:
	std::shared_ptr<Filter> myMultiplier;
	std::shared_ptr<Filter> myMultiplicand;

public:
	MultiplyFilter(const std::shared_ptr<Filter>& multiplier, const std::shared_ptr<Filter>& multiplicand);
	~MultiplyFilter();

private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};

