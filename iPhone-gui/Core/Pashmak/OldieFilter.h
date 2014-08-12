#pragma once
#include "Filter.h"

class OldieFilter final :
	public Filter
{
private:
	unsigned int LineNumber;

public:
	OldieFilter(unsigned int lineNumber);
	~OldieFilter();

private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};
