#pragma once
#include <vector>
#include "Filter.h"

class AggregatedFilter final :
	public Filter
{
private:
	std::vector<std::shared_ptr<Filter>> myFilters;

public:
	AggregatedFilter(const std::vector<std::shared_ptr<Filter>>& filters);
	~AggregatedFilter();

	std::shared_ptr<Media> Apply(const std::shared_ptr<Media>& media) override;
};

