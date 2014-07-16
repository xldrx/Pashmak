#pragma once
#include "PictureFilter.h"

class ColorReductionFilter final :
public PictureFilter
{
private:
	int Div;
	
public:
	ColorReductionFilter(int Div);
	~ColorReductionFilter();
    
private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};
