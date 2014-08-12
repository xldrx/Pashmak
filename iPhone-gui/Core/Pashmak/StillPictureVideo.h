#pragma once
#include "Video.h"

class StillPictureVideo :
	public Video
{
private:
	std::shared_ptr<Picture> myPic;

public:
	StillPictureVideo(const std::shared_ptr<Picture>& pic);
	~StillPictureVideo();

	unsigned int GetLength() override;
	void GotoFrame(unsigned int frame) override;
	bool GetNextFrame(std::shared_ptr<Picture>& frame) override;
};

