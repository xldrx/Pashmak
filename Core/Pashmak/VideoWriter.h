#pragma once
#include "Picture.h"

class VideoWriter
{
private:
	cv::VideoWriter myVideoWriter;

public:
	VideoWriter(const cv::VideoWriter& video);
	~VideoWriter();

	void Write(const std::shared_ptr<Picture>& pic);
};

