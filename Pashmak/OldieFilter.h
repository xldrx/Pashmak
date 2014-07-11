#pragma once
#include "PictureFilter.h"

class OldieFilter final :
	public PictureFilter
{
private:
	unsigned int LineNumber;

public:
	OldieFilter(unsigned int lineNumber);
	~OldieFilter();

	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};

