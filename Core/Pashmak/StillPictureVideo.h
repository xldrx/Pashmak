#pragma once
#include "Video.h"

class StillPictureVideo :
	public Video
{
private:
	std::shared_ptr<Picture> myPic;
	unsigned int myCurrentFrame;
	unsigned int myLength;

public:
	StillPictureVideo(const std::shared_ptr<Picture>& pic, unsigned int length);
	~StillPictureVideo();

	bool GetNextFrame(std::shared_ptr<Picture>& frame) override;
};

