#include "StillPictureVideo.h"

StillPictureVideo::StillPictureVideo(const std::shared_ptr<Picture>& pic, unsigned int length)
	: myPic(pic)
	, myLength(length)
	, myCurrentFrame(0)
{
}

StillPictureVideo::~StillPictureVideo()
{
}

bool StillPictureVideo::GetNextFrame(std::shared_ptr<Picture>& frame)
{
	frame = std::make_shared<Picture>(myPic->Mat().clone());
	return ++myCurrentFrame < myLength;
}
