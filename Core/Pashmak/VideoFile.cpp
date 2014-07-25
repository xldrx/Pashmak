#include "VideoFile.h"
#include "Configuration.h"

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

	cv::resize(src, frame->Mat(), cv::Size(Configuration::GetOutputWidth(), Configuration::GetOutputHeight()));
	return true;
}

unsigned int VideoFile::GetLength()
{
	return myVideoCapture->get(CV_CAP_PROP_FRAME_COUNT);
}

void VideoFile::GotoFrame(unsigned int frame)
{
	myVideoCapture->set(CV_CAP_PROP_POS_FRAMES, frame);
}
