#include "VideoWriter.h"
#include "Configuration.h"

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
	
	cv::resize(pic->Mat(), res, cv::Size(Configuration::GetOutputWidth(), Configuration::GetOutputHeight()));
	
	myVideoWriter.write(res);
}
