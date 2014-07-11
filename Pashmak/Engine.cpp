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
	
	auto zoe(std::make_shared<Media>());
	for (unsigned int cutId = 0; cutId < myTheme->GetNumberOfCuts(); cutId++)
	{
		// TODO: This should be Append
		//zoe->Append(myTheme->GenerateRandomCut(medias));
		zoe = myTheme->GenerateRandomCut(medias);
	}

	auto filter = myTheme->GetFilter();
	return filter->Apply(zoe);
}