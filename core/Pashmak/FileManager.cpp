#include "FileManager.h"
#include "Picture.h"
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <locale>
#include <codecvt>

#ifdef WIN32

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#endif

namespace
{
	std::wstring s2ws(const std::string& str)
	{
		typedef std::codecvt_utf8<wchar_t> convert_typeX;
		std::wstring_convert<convert_typeX, wchar_t> converterX;

		return converterX.from_bytes(str);
	}

	std::string ws2s(const std::wstring& wstr)
	{
		typedef std::codecvt_utf8<wchar_t> convert_typeX;
		std::wstring_convert<convert_typeX, wchar_t> converterX;

		return converterX.to_bytes(wstr);
	}

	std::vector<std::wstring> GetAllFilesInFolderWide(const std::wstring& foldername)
	{
		std::vector<std::wstring> out;

#ifdef WIN32
		HANDLE dir;
		WIN32_FIND_DATA file_data;

		if ((dir = FindFirstFile((foldername + L"/*").c_str(), &file_data)) == INVALID_HANDLE_VALUE)
			return out; /* No files found */

		do {
			const std::wstring file_name = file_data.cFileName;
			const std::wstring full_file_name = foldername + L"/" + file_name;
			const bool is_directory = (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;

			if (file_name[0] == '.')
				continue;

			if (is_directory)
				continue;

			out.push_back(full_file_name);
		} while (FindNextFile(dir, &file_data));

		FindClose(dir);
#endif

		return out;
	}

	std::vector<std::string> GetAllFilesInFolder(const std::string& foldername)
	{
		std::vector<std::string> out;
		
		for (const auto& wfilename : GetAllFilesInFolderWide(s2ws(foldername)))
			out.push_back(ws2s(wfilename));

		return out;
	}

	std::string GetFilenameExtension(const std::string& filename)
	{
		return filename.substr(filename.find_last_of(".") + 1);
	}

	bool IsPicture(const std::string& filename)
	{
		return GetFilenameExtension(filename) == "jpg";
	}

	std::shared_ptr<Picture> LoadPicture(const std::string& filename)
	{
		return std::make_shared<Picture>(cv::imread(filename));
	}

	void SavePicture(const std::shared_ptr<Picture>& pic, const std::string& filename)
	{
		cv::imwrite(filename, pic->Mat());
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
	return IsPicture(filename) ? LoadPicture(filename) : std::make_shared<Media>();
}

std::vector<std::shared_ptr<Media>> FileManager::LoadFiles(const std::vector<std::string>& filenames) const
{
	std::vector<std::shared_ptr<Media>> output;
	for (const auto& filename : filenames)
		output.push_back(LoadFile(filename));

	return output;
}

std::vector<std::shared_ptr<Media>> FileManager::LoadFolder(const std::string& foldername) const
{
	return LoadFiles(GetAllFilesInFolder(foldername));
}

void FileManager::SaveFile(const std::shared_ptr<Media>& media, const std::string& filename) const
{
	const auto& pic(std::dynamic_pointer_cast<Picture>(media));
	if (pic)
		SavePicture(pic, filename);

	return;
}
