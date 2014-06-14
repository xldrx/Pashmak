#include "Constants.h"
#include "Engine.h"
#include "FileManager.h"
#include <iostream>
#include <string>

void PrintUsage()
{
	std::cout << "app.exe inputfolder outputfile" << std::endl;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		PrintUsage();
		exit(0);
	}

	FileManager myFileManager;
	Engine myEngine;

	auto media = myFileManager.LoadFolder(std::string(argv[1]));
	auto output = myEngine.CreateZoe(media, Themes::Action);
	myFileManager.SaveFile(output, std::string(argv[2]));

	return 0;
}