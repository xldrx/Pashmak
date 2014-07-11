#include "ThemeFactory.h"
#include "ClassicTheme.h"

ThemeFactory::ThemeFactory()
{
}

ThemeFactory::~ThemeFactory()
{
}

std::shared_ptr<Theme> ThemeFactory::LoadTheme(Themes theme)
{
	switch (theme)
	{
	case Classic:
	case Romance:
	case Action:
	case Party:
	case Mood:
	case Workout:
	case Chill:
	case Travel:
	default:
		return std::make_shared<ClassicTheme>();
		break;
	}
}