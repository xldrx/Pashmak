//
//  BilateralBlurFilter.h
//  OpenCV
//
//  Created by Mehran on 7/15/14.
//  Copyright (c) 2014 Mehran. All rights reserved.
//
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
