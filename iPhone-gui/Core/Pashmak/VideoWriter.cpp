#include "VideoWriter.h"
#include "Configuration.h"

VideoWriter::VideoWriter(const cv::VideoWriter& video)
	: myVideoWriter(video)
	, myFrameCount(0)
{
}

VideoWriter::~VideoWriter()
{
}

void VideoWriter::Write(const std::shared_ptr<Picture>& pic)
{
	cv::Mat res;
	cv::resize(pic->Mat(), res, cv::Size(Configuration::GetOutputWidth(), Configuration::GetOutputHeight()));
	myVideoWriter.write(res);
	myFrameCount++;
}

int VideoWriter::GetFramesCount()
{
	return myFrameCount;
}
