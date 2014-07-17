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

private:
	std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& media) override;
};

