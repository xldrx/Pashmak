#include "VideoFilter.h"

VideoFilter::VideoFilter(const std::shared_ptr<Video>& video)
	: myVideo(video)
{
}

VideoFilter::~VideoFilter()
{
}

std::shared_ptr<Picture> VideoFilter::ApplyImpl(const std::shared_ptr<Picture>& pic)
{
	auto frame = std::make_shared<Picture>(cv::Mat());
	if (!myVideo->GetNextFrame(frame))
	{
		myVideo->GotoFrame(0);
		if (!myVideo->GetNextFrame(frame))
		{
			throw std::exception("Something went wrong in VideoFilter");
		}
	}

	const auto& a = pic->Mat();
	auto b = frame->Mat();

	cv::addWeighted(a, 0.5, b, 0.5, 0.0, b);
	return std::make_shared<Picture>(b);
}

