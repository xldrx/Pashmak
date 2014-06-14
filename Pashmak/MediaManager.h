#pragma once
#include "Media.h"
#include <memory>
#include <string>
#include <vector>

class MediaManager
{
public:
	MediaManager();
	~MediaManager();

	std::shared_ptr<Media> Load(const std::string& filename);
	std::vector<std::shared_ptr<Media>> Load(const std::vector<const std::string&>& filenames);
	void Save(const std::shared_ptr<Media>& media, const std::string& filename);
};

