#include "OldieTheme.h"
#include "AggregatedFilter.h"
#include "GaussianWindowFilter.h"
#include "GaussianNoiseFilter.h"
#include "OldieFilter.h"
#include "SepiaFilter.h"

OldieTheme::OldieTheme()
{
}

OldieTheme::~OldieTheme()
{
}

unsigned int OldieTheme::GetNumberOfCuts()
{
	return 1;
}

std::shared_ptr<Media> OldieTheme::GenerateRandomCut(const std::vector<std::shared_ptr<Media>>& medias)
{
	return medias[0];
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
