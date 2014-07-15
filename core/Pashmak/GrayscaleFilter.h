#pragma once
#include "PictureFilter.h"

class GrayscaleFilter final :
	public PictureFilter
{
public:
	GrayscaleFilter();
	~GrayscaleFilter();

private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};

