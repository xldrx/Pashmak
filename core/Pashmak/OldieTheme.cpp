#include "OldieTheme.h"
#include "AggregatedFilter.h"
#include "GaussianWindowFilter.h"
#include "GaussianNoiseFilter.h"
#include "OldieFilter.h"
#include "SepiaFilter.h"
#include "VideoFilter.h"
#include "VideoFile.h"
#include "Utils.h"
#include "Configuration.h"

OldieTheme::OldieTheme()
{
}

OldieTheme::~OldieTheme()
{
}

unsigned int OldieTheme::GetNumberOfCuts()
{
	return 30;
}

std::shared_ptr<Video> OldieTheme::GenerateRandomCut(const std::vector<std::shared_ptr<Media>>& medias)
{
	return Utils::GetRandomVideoCut(medias, 1.0);
}

std::shared_ptr<Filter> OldieTheme::GetFilter()
{
    auto addr = Configuration::GetOverlayVideo();
	std::vector<std::shared_ptr<Filter>> filters =
	{
//		std::make_shared<GaussianWindowFilter>(),
//		std::make_shared<GaussianNoiseFilter>(1, 5),
//		std::make_shared<OldieFilter>(10),
//		std::make_shared<SepiaFilter>()
		std::make_shared<VideoFilter>(std::make_shared<VideoFile>(addr))
	};
    std::cerr << "xl:" << addr;
	return std::make_shared<AggregatedFilter>(filters);
}
