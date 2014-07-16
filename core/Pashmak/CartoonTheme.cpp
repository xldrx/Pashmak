#include "CartoonTheme.h"
#include "AggregatedFilter.h"
#include "ColorReductionFilter.h"
#include "BilateralBlurFilter.h"
#include "MultiplyFilter.h"
#include "SobelEdgeFilter.h"

CartoonTheme::CartoonTheme()
{
}

CartoonTheme::~CartoonTheme()
{
}

unsigned int CartoonTheme::GetNumberOfCuts()
{
	return 1;
}

std::shared_ptr<Media> CartoonTheme::GenerateRandomCut(const std::vector<std::shared_ptr<Media>>& medias)
{
	return medias[0];
}

std::shared_ptr<Filter> CartoonTheme::GetFilter()
{
	std::vector<std::shared_ptr<Filter>> filters =
	{
		std::make_shared<BilateralBlurFilter>(15, 50.0, 50.0),
        std::make_shared<ColorReductionFilter>(8)
    };
    
    std::vector<std::shared_ptr<Filter>> filters2 =
	{
        std::make_shared<MultiplyFilter>(std::make_shared<AggregatedFilter>(filters),std::make_shared<SobelEdgeFilter>()),
		std::make_shared<BilateralBlurFilter>(15, 50.0, 50.0)
    };
    
	return std::make_shared<AggregatedFilter>(filters2);
}


