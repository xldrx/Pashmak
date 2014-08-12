#pragma once
#include "Filter.h"

class SepiaFilter final :
	public Filter
{
private:
	cv::Mat SepiaKernel;

public:
	SepiaFilter();
	~SepiaFilter();

private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};

