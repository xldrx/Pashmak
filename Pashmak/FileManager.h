#pragma once
#include "Media.h"
#include <memory>
#include <string>
#include <vector>

class FileManager
{
public:
	FileManager();
	~FileManager();

	std::shared_ptr<Media> LoadFile(const std::string& filename) const;
	std::vector<std::shared_ptr<Media>> LoadFolder(const std::string& foldername) const;
	std::vector<std::shared_ptr<Media>> LoadFiles(const std::vector<std::string>& filenames) const;
	void SaveFile(const std::shared_ptr<Media>& media, const std::string& filename) const;
};

