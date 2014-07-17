#pragma once
#include "Filter.h"

class GrayscaleFilter final :
	public Filter
{
public:
	GrayscaleFilter();
	~GrayscaleFilter();

private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};

