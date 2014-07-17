#include "VideoWriter.h"

VideoWriter::VideoWriter(const cv::VideoWriter& video)
	: myVideoWriter(video)
{
}

VideoWriter::~VideoWriter()
{
}

void VideoWriter::Write(const std::shared_ptr<Picture>& pic)
{
	cv::Mat res;
	
	cv::resize(pic->Mat(), res, cv::Size(512, 512));
	
	myVideoWriter.write(res);
}
