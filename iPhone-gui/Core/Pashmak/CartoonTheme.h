#pragma once
#include "Theme.h"

class CartoonTheme final :
public Theme
{
public:
	CartoonTheme();
	~CartoonTheme();
    
	unsigned int GetNumberOfCuts() override;
	std::shared_ptr<Video> GenerateRandomCut(const std::vector<std::shared_ptr<Media>>& medias) override;
	std::shared_ptr<Filter> GetFilter() override;

	std::shared_ptr<Transition> GetTransition() override;
	unsigned int GetTransitionLength() override;
};

