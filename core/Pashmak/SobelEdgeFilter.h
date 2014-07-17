#pragma once
#include "Filter.h"

class SobelEdgeFilter final :
	public Filter
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
