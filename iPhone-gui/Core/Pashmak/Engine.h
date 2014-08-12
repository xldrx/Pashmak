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

	void CreateZoe(const std::vector<std::shared_ptr<Media>>& medias, Themes theme, const std::string& outputFilename);
   	void CreateZoe(const std::vector<std::shared_ptr<Media>>& medias, Themes theme, const std::string& outputFilename, const std::string& background);
};
