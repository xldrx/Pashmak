#include "VideoCut.h"

VideoCut::VideoCut(const std::shared_ptr<Video>& video, unsigned int length)
	: myVideo(video)
	, myLength(length)
	, myCurrentFrame(0)
{
	auto movielength = myVideo->GetLength();
	auto r = length > movielength ? 0 : rand() % (movielength + 1);
	myVideo->GotoFrame(r);
}

VideoCut::~VideoCut()
{
}

unsigned int VideoCut::GetLength()
{
	return myLength;
}

void VideoCut::GotoFrame(unsigned int frame)
{
	myCurrentFrame = frame;
}

bool VideoCut::GetNextFrame(std::shared_ptr<Picture>& frame)
{
	if (myCurrentFrame >= myLength)
		return false;

	myCurrentFrame++;
	return myVideo->GetNextFrame(frame);
}
