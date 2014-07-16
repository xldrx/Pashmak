//
//  SobelEdgeFilter.h
//  OpenCV
//
//  Created by Mehran on 7/15/14.
//  Copyright (c) 2014 Mehran. All rights reserved.
//

#pragma once
#include "PictureFilter.h"


class SobelEdgeFilter final :
public PictureFilter
{
private:
    const int Depth = CV_16S;
	const int Scale = 1;
    const int Delta = 0;
    
public:
	SobelEdgeFilter();
	~SobelEdgeFilter();
    
private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};
