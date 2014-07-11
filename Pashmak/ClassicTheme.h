#pragma once
#include "Theme.h"
class ClassicTheme final :
	public Theme
{
public:
	ClassicTheme();
	~ClassicTheme();

	unsigned int GetNumberOfCuts() override;
	std::shared_ptr<Media> GenerateRandomCut(const std::vector<std::shared_ptr<Media>>& medias) override;
	std::shared_ptr<Filter> GetFilter() override;
};

