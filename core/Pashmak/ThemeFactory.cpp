#include "ThemeFactory.h"
#include "OldieTheme.h"

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
	case Oldie:
		return std::make_shared<OldieTheme>();
	
	default:
		//throw std::exception("Unkown theme");
		break;
	}
}