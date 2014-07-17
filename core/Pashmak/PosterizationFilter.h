#pragma once
#include "Filter.h"

class PosterizationFilter final :
	public Filter
{
public:
	PosterizationFilter();
	~PosterizationFilter();

private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};

