#pragma once
#include "PictureFilter.h"

class BilateralBlurFilter final :
	public PictureFilter
{
private:
	int Diameter;
	double SigmaColor;
    double SigmaSpace;
    
public:
	BilateralBlurFilter(int Diameter, double SigmaColor, double SigmaSpace);
	~BilateralBlurFilter();
    
private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};
