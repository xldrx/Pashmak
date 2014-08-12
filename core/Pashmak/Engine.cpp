#include "Engine.h"
#include "ThemeFactory.h"
#include "VideoWriter.h"
#include "Configuration.h"

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

	VideoWriter zoe(cv::VideoWriter(outputFilename, CV_FOURCC('D', 'M', '4', 'V'),
		Configuration::GetOutputFps(), cv::Size(Configuration::GetOutputWidth(), Configuration::GetOutputHeight())));
	for (unsigned int cutId = 0; cutId < theme->GetNumberOfCuts(); cutId++)
	{
		auto cut(theme->GenerateRandomCut(medias));
		auto frame = std::make_shared<Picture>(cv::Mat());
		while (cut->GetNextFrame(frame))
		{
			try
			{
				zoe.Write(filter->Apply(frame));
			}
			catch (...)
			{
			}
		}
	}
}

void Engine::CreateZoe(const std::vector<std::shared_ptr<Media>>& medias, Themes theme, const std::string& outputFilename, const std::string& background){
    Configuration::SetOverlayVideo(background);
    this->CreateZoe(medias, theme, outputFilename);
}