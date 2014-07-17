#pragma once
#include "Filter.h"

class GaussianNoiseFilter final :
	public Filter
{
private: 
	int Mean;
	int StdDev;

public:
	GaussianNoiseFilter(int mean, int stddev);
	~GaussianNoiseFilter();

private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};

