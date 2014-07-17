#include "Constants.h"
#include "Engine.h"
#include "FileManager.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>

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

	std::clock_t start;
	double duration;
	start = std::clock();

	myEngine.CreateZoe(media, Themes::Cartoon, std::string(argv[2]));

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Time: " << duration << '\n';

	return 0;
}