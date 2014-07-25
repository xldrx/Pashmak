#include "Utils.h"
#include "StillPictureVideo.h"
#include "VideoFile.h"
#include "Configuration.h"

std::shared_ptr<Video> Utils::GetRandomVideo(const std::vector<std::shared_ptr<Media>>& medias)
{
	auto r = rand() % medias.size();
	std::cerr << r << std::endl;
	auto media = medias.at(r);

	auto pic = std::dynamic_pointer_cast<Picture>(media);
	if (pic)
		return std::make_shared<StillPictureVideo>(pic);
	else
		return std::static_pointer_cast<VideoFile>(media);
}

std::shared_ptr<VideoCut> Utils::GetRandomVideoCut(const std::vector<std::shared_ptr<Media>>& medias, unsigned int length)
{
	return std::make_shared<VideoCut>(Utils::GetRandomVideo(medias), length);
}

std::shared_ptr<VideoCut> Utils::GetRandomVideoCut(const std::vector<std::shared_ptr<Media>>& medias, double seconds)
{
	return Utils::GetRandomVideoCut(medias, static_cast<unsigned int>(Configuration::GetOutputFps() * seconds));
}


