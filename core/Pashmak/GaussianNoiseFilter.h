#pragma once
#include "PictureFilter.h"

class GaussianNoiseFilter final :
	public PictureFilter
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

