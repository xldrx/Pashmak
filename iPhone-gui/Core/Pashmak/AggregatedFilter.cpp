#include "AggregatedFilter.h"

AggregatedFilter::AggregatedFilter(const std::vector<std::shared_ptr<Filter>>& filters)
	: myFilters(filters)
{
}

AggregatedFilter::~AggregatedFilter()
{
}

std::shared_ptr<Picture> AggregatedFilter::ApplyImpl(const std::shared_ptr<Picture>& media)
{
	auto out = media;
	
	for (const auto& filter : myFilters)
		out = filter->Apply(out);

	return out;
}

