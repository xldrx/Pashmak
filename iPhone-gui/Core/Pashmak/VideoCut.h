#pragma once
#include "Video.h"
class VideoCut :
	public Video
{
private:
	std::shared_ptr<Video> myVideo;
	unsigned int myCurrentFrame;
	unsigned int myLength;

public:
	VideoCut(const std::shared_ptr<Video>& video, unsigned int length);
	~VideoCut();

	unsigned int GetLength() override;
	void GotoFrame(unsigned int frame) override;
	bool GetNextFrame(std::shared_ptr<Picture>& frame) override;
};

