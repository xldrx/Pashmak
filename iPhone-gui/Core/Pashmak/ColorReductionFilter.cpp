#include "ColorReductionFilter.h"

ColorReductionFilter::ColorReductionFilter(int div)
: Div(div)
{
}

ColorReductionFilter::~ColorReductionFilter()
{
}

std::shared_ptr<Picture> ColorReductionFilter::ApplyImpl(const std::shared_ptr<Picture>& pic)
{
	const auto& src = pic->Mat();
    cv::Mat res(src.size(),src.type());
    
    uchar buffer[256];
    for(size_t i = 0; i != 256; ++i){
        buffer[i] = i / Div * Div + Div / 2;
    }
    cv::Mat table(1, 256, CV_8U, buffer, sizeof(buffer));
    cv::LUT(src, table, res);
    
    return std::make_shared<Picture>(res);
}