#include "OldieTheme.h"
#include "AggregatedFilter.h"
#include "Configuration.h"
#include "FadingTransition.h"
#include "GaussianWindowFilter.h"
#include "GaussianNoiseFilter.h"
#include "OldieFilter.h"
#include "SepiaFilter.h"
#include "VideoFilter.h"
#include "VideoFile.h"
#include "Utils.h"

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
	return Utils::GetRandomVideoCut(medias, 2.0);
}

std::shared_ptr<Filter> OldieTheme::GetFilter()
{
	std::vector<std::shared_ptr<Filter>> filters =
	{
		//std::make_shared<GaussianWindowFilter>(),
		//std::make_shared<GaussianNoiseFilter>(1, 5),
		//std::make_shared<OldieFilter>(10),
		//std::make_shared<SepiaFilter>()
		std::make_shared<VideoFilter>(std::make_shared<VideoFile>("C:\\Users\\Mohammad\\Documents\\visual studio 2013\\Projects\\Pashmak\\Core\\Assets\\filmscratches.m4v"))
	};

	return std::make_shared<AggregatedFilter>(filters);
}

std::shared_ptr<Transition> OldieTheme::GetTransition()
{
	return std::make_shared<FadingTransition>();
}

unsigned int OldieTheme::GetTransitionLength()
{
	return Configuration::GetOutputFps();
}
