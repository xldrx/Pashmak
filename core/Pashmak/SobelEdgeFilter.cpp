//
//  SobelEdgeFilter.cpp
//  OpenCV
//
//  Created by Mehran on 7/15/14.
//  Copyright (c) 2014 Mehran. All rights reserved.
//

#include "SobelEdgeFilter.h"

SobelEdgeFilter::SobelEdgeFilter()
{
}

SobelEdgeFilter::~SobelEdgeFilter()
{
}

//normalized (0,1) and inverted Sobel edge detector
std::shared_ptr<Picture> SobelEdgeFilter::ApplyImpl(const std::shared_ptr<Picture>& pic)
{
	const auto& src = pic->Mat();
    double minVal, maxVal;
    cv::Mat res;
    cv::Mat XGrad, YGrad;
    cv::Mat XGradAbs, YGradAbs;
    
    Sobel( src, XGrad, Depth, 1, 0, 3, Scale, Delta, cv::BORDER_DEFAULT );
    convertScaleAbs( XGrad, XGradAbs );
    
    Sobel( src, YGrad, Depth, 0, 1, 3, Scale, Delta, cv::BORDER_DEFAULT );
    convertScaleAbs( YGrad, YGradAbs );
    
    addWeighted( XGradAbs, 0.5, YGradAbs, 0.5, 0, res );
    
    cvtColor(res, res, CV_BGR2GRAY);
    
    minMaxLoc(res, &minVal, &maxVal);
    res.convertTo(res, CV_64F,1/(maxVal - minVal));
    minMaxLoc(res, &minVal, &maxVal);
    res =  1 - res;

    return std::make_shared<Picture>(res);
}