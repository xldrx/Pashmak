#pragma once
#include "Filter.h"

class GaussianWindowFilter final :
	public Filter
{
public:
	GaussianWindowFilter();
	~GaussianWindowFilter();

private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};

