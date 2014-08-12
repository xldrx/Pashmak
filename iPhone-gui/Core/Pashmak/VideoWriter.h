#pragma once
#include "Picture.h"

class VideoWriter
{
private:
	cv::VideoWriter myVideoWriter;
	unsigned int myFrameCount;

public:
	VideoWriter(const cv::VideoWriter& video);
	~VideoWriter();

	void Write(const std::shared_ptr<Picture>& pic);
	int GetFramesCount();
};

