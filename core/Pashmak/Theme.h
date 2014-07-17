#pragma once
#include "Media.h"
#include "Video.h"
#include "Filter.h"
#include <memory>
#include <vector>

class Theme
{
public:
	Theme();
	~Theme();

	virtual unsigned int GetNumberOfCuts() = 0;
	virtual std::shared_ptr<Video> GenerateRandomCut(const std::vector<std::shared_ptr<Media>>& medias) = 0;
	virtual std::shared_ptr<Filter> GetFilter() = 0;
};

