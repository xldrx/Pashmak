#pragma once
#include "Constants.h"
#include "Media.h"
#include <memory>
#include <vector>

class Engine
{
public:
	Engine();
	~Engine();

	std::shared_ptr<Media> CreateZoe(const std::vector<std::shared_ptr<Media>>& medias, Themes theme);
};

