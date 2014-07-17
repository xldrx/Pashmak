#include "OldieTheme.h"
#include "AggregatedFilter.h"
#include "GaussianWindowFilter.h"
#include "GaussianNoiseFilter.h"
#include "OldieFilter.h"
#include "SepiaFilter.h"
#include "VideoFile.h"
#include "StillPictureVideo.h"

OldieTheme::OldieTheme()
{
}

OldieTheme::~OldieTheme()
{
}

unsigned int OldieTheme::GetNumberOfCuts()
{
	return 3;
}

std::shared_ptr<Video> OldieTheme::GenerateRandomCut(const std::vector<std::shared_ptr<Media>>& medias)
{
	auto r = rand() % medias.size();
	std::cerr << r << std::endl;
	auto media = medias.at(r);

	auto pic = std::dynamic_pointer_cast<Picture>(media);
	if (pic)
		return std::make_shared<StillPictureVideo>(pic, 24 * 5);
	else
		return std::static_pointer_cast<VideoFile>(media);
}

std::shared_ptr<Filter> OldieTheme::GetFilter()
{
	std::vector<std::shared_ptr<Filter>> filters =
	{
		std::make_shared<GaussianWindowFilter>(),
		std::make_shared<GaussianNoiseFilter>(1, 5),
		std::make_shared<OldieFilter>(10),
		std::make_shared<SepiaFilter>()
	};

	return std::make_shared<AggregatedFilter>(filters);
}
