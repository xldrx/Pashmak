#include "StillPictureVideo.h"

StillPictureVideo::StillPictureVideo(const std::shared_ptr<Picture>& pic)
	: myPic(pic)
{
}

StillPictureVideo::~StillPictureVideo()
{
}

bool StillPictureVideo::GetNextFrame(std::shared_ptr<Picture>& frame)
{
	frame = std::make_shared<Picture>(myPic->Mat().clone());
	return true;
}

unsigned int StillPictureVideo::GetLength()
{
	return 0;
}

void StillPictureVideo::GotoFrame(unsigned int frame)
{
	return;
}


