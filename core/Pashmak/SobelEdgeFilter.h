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
