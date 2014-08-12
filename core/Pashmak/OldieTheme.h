#pragma once
#include "Theme.h"
#include <string>

class OldieTheme final :
	public Theme
{
public:
	OldieTheme();
	~OldieTheme();

	unsigned int GetNumberOfCuts() override;
	std::shared_ptr<Video> GenerateRandomCut(const std::vector<std::shared_ptr<Media>>& medias) override;
	std::shared_ptr<Filter> GetFilter() override;
};
