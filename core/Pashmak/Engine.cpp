#include "Engine.h"
#include "ThemeFactory.h"
#include "VideoWriter.h"

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::CreateZoe(const std::vector<std::shared_ptr<Media>>& medias, Themes themes, const std::string& outputFilename)
{
	ThemeFactory myThemeFactory;
	auto theme = myThemeFactory.LoadTheme(themes);
	auto filter = theme->GetFilter();

	VideoWriter zoe(cv::VideoWriter(outputFilename, CV_FOURCC('W', 'M', 'V', '1'), 24, cv::Size(512, 512)));
	for (unsigned int cutId = 0; cutId < theme->GetNumberOfCuts(); cutId++)
	{
		auto cut(theme->GenerateRandomCut(medias));
		auto frame = std::make_shared<Picture>(cv::Mat());
		while (cut->GetNextFrame(frame))
			zoe.Write(filter->Apply(frame));
	}
}