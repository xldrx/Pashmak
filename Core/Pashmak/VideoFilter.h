#pragma once
#include "Filter.h"
#include "Video.h"

class VideoFilter :
	public Filter
{
private:
	std::shared_ptr<Video> myVideo;

public:
	VideoFilter(const std::shared_ptr<Video>& video);
	~VideoFilter();

	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) override;
};

