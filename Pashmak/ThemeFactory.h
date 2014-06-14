#pragma once
#include "Constants.h"
#include "Theme.h"

class ThemeFactory
{
public:
	ThemeFactory();
	~ThemeFactory();

	Theme LoadTheme(Themes theme);
};

