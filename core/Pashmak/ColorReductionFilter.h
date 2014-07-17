#pragma once
#include "Filter.h"

class ColorReductionFilter final :
public Filter
{
private:
	int Div;
	
public:
	ColorReductionFilter(int Div);
	~ColorReductionFilter();
    
private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};
