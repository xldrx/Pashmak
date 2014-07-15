#pragma once
#include "PictureFilter.h"

class GaussianWindowFilter final :
	public PictureFilter
{
public:
	GaussianWindowFilter();
	~GaussianWindowFilter();

private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};

