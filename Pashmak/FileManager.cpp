#include "FileManager.h"

namespace
{
	std::vector<std::string> GetAllFilesInFolder(const std::string& foldername)
	{
		return std::vector<std::string>();
	}
}

FileManager::FileManager()
{
}

FileManager::~FileManager()
{
}

std::shared_ptr<Media> FileManager::LoadFile(const std::string& filename) const
{
	return std::make_shared<Media>();
}

std::vector<std::shared_ptr<Media>> FileManager::LoadFolder(const std::string& foldername) const
{
	std::vector<std::shared_ptr<Media>> output;
	for (const auto& filename : GetAllFilesInFolder(foldername))
	{
		output.push_back(LoadFile(filename));
	}

	return output;
}

void FileManager::SaveFile(const std::shared_ptr<Media>& media, const std::string& filename) const
{
	return;
}
