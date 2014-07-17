#pragma once
#include "Filter.h"

class BilateralBlurFilter final :
	public Filter
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
