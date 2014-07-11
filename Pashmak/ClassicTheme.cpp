#include "ClassicTheme.h"
#include "AggregatedFilter.h"
#include "GaussianNoiseFilter.h"
#include "OldieFilter.h"
#include <vector>

ClassicTheme::ClassicTheme()
{
}

ClassicTheme::~ClassicTheme()
{
}

unsigned int ClassicTheme::GetNumberOfCuts()
{
	return 1;
}

std::shared_ptr<Media> ClassicTheme::GenerateRandomCut(const std::vector<std::shared_ptr<Media>>& medias)
{
	return medias[0];
}

std::shared_ptr<Filter> ClassicTheme::GetFilter()
{
	std::vector<std::shared_ptr<Filter>> filters = 
	{
		std::make_shared<GaussianNoiseFilter>(1, 5),
		std::make_shared<OldieFilter>(10)
	};

	return std::make_shared<AggregatedFilter>(filters);
}
