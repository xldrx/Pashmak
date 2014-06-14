#include "Engine.h"
#include "ThemeFactory.h"

Engine::Engine()
{
}

Engine::~Engine()
{
}

std::shared_ptr<Media> Engine::CreateZoe(const std::vector<std::shared_ptr<Media>>& medias, Themes theme)
{
	ThemeFactory myThemeFactory;
	auto myTheme = myThemeFactory.LoadTheme(theme);
	
	auto output = std::make_shared<Media>();
	for (int cutId = 0; cutId < myTheme.GetNumberOfCuts(); cutId++)
	{
		output->Append(myTheme.GenerateRandomCut(medias));
	}

	return output;
}