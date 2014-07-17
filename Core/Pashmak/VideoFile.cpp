#include "VideoFile.h"

VideoFile::VideoFile(const std::string& filename)
	: myVideoCapture(std::make_shared<cv::VideoCapture>(filename))
{
}

VideoFile::~VideoFile()
{
	myVideoCapture->release();
}

bool VideoFile::GetNextFrame(std::shared_ptr<Picture>& frame)
{
	cv::Mat src;
	if (!myVideoCapture->read(src))
		return false;

	resize(src, frame->Mat(), cv::Size(512, 512));
	return true;
}
