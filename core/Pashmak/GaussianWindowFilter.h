#pragma once
#include "PictureFilter.h"
#include "NoOpFilter.h"
#include "MultiplyFilter.h"

class GaussianWindowFilter final :
	public PictureFilter
{
public:
	GaussianWindowFilter();
	~GaussianWindowFilter();

private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};

