#pragma once
#include "Constants.h"
#include "Theme.h"

class ThemeFactory
{
public:
	ThemeFactory();
	~ThemeFactory();

	std::shared_ptr<Theme> LoadTheme(Themes theme);
};

