#pragma once
#include "PictureFilter.h"

class SepiaFilter final :
	public PictureFilter
{
private:
	cv::Mat SepiaKernel;

public:
	SepiaFilter();
	~SepiaFilter();

private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};

