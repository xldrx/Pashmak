#pragma once
#include "PictureFilter.h"

class MultiplyFilter :
	public PictureFilter
{
private:
	std::shared_ptr<PictureFilter> myMultiplier;
	std::shared_ptr<PictureFilter> myMultiplicand;

public:
	MultiplyFilter(const std::shared_ptr<PictureFilter>& multiplier, const std::shared_ptr<PictureFilter>& multiplicand);
	~MultiplyFilter();

private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};

