#pragma once
#include "VideoCut.h"

class Utils
{
public:
	static std::shared_ptr<Video> GetRandomVideo(const std::vector<std::shared_ptr<Media>>& medias);
	static std::shared_ptr<VideoCut> GetRandomVideoCut(const std::vector<std::shared_ptr<Media>>& medias, unsigned int length);
	static std::shared_ptr<VideoCut> GetRandomVideoCut(const std::vector<std::shared_ptr<Media>>& medias, double seconds);
};

