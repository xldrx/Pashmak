#pragma once
#include "PictureFilter.h"

class PosterizationFilter final :
	public PictureFilter
{
public:
	PosterizationFilter();
	~PosterizationFilter();

private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};

