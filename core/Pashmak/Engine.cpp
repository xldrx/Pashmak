#include "Engine.h"
#include "ThemeFactory.h"
#include "VideoWriter.h"
#include "Configuration.h"

namespace
{
	std::shared_ptr<VideoWriter> InitOutputVideo(const std::string& outputFilename)
	{
#ifdef WIN32
		return std::make_shared<VideoWriter>(cv::VideoWriter(outputFilename, CV_FOURCC('W', 'M', 'V', '1'),
			Configuration::GetOutputFps(), cv::Size(Configuration::GetOutputWidth(), Configuration::GetOutputHeight())));
#else
		return std::make_shared<VideoWriter>(cv::VideoWriter(outputFilename, CV_FOURCC('D', 'M', '4', 'V'),
			Configuration::GetOutputFps(), cv::Size(Configuration::GetOutputWidth(), Configuration::GetOutputHeight())));
#endif
	}

	std::shared_ptr<Picture> TryGetFrame(const std::shared_ptr<Video>& cut)
	{
		auto frame = std::make_shared<Picture>(cv::Mat());
		if (!cut->GetNextFrame(frame))
			throw std::runtime_error("Cut ran out pf frames before it should have");
		return frame;
	}

	void GenerateZoeVideo(
		const std::shared_ptr<VideoWriter>& zoe, 
		const std::shared_ptr<Theme>& theme, 
		const std::vector<std::shared_ptr<Media>>& medias)
	{
		int outputFrameCount = Configuration::GetOutputFps() * Configuration::GetOutputDuration();
		auto filter = theme->GetFilter();
		auto transition = theme->GetTransition();
		auto transitionLength = theme->GetTransitionLength();

		auto cut1(theme->GenerateRandomCut(medias));
		auto cut1length = cut1->GetLength();
		while (zoe->GetFramesCount() < outputFrameCount)
		{
			auto cut2(theme->GenerateRandomCut(medias));
			auto cut2length = cut2->GetLength();

			if (cut1length < transitionLength || cut2length < transitionLength)
				throw std::runtime_error("Cut length cannot be smaller than transition length");

			auto frame = std::make_shared<Picture>(cv::Mat());

			for (unsigned int frameCount = 0; frameCount < cut1length; frameCount++)
			{
				if (frameCount < cut1length - transitionLength)
					frame = TryGetFrame(cut1);
				else
					frame = transition->Transit(TryGetFrame(cut1), TryGetFrame(cut2),
					static_cast<float>(cut1length - frameCount) / transitionLength);

				try
				{
					zoe->Write(filter->Apply(frame));
				}
				catch (...) {}

				if (zoe->GetFramesCount() >= outputFrameCount)
					break;
			}

			cut1 = cut2;
			cut1length = cut2length - transitionLength;
		}
	}
}

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

	auto zoe = InitOutputVideo(outputFilename);
	GenerateZoeVideo(zoe, theme, medias);
}