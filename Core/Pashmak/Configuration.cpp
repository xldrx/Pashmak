#include "Configuration.h"

Configuration::Configuration()
{
}

Configuration::~Configuration()
{
}

int Configuration::GetOutputWidth()
{
	return 640;
}

int Configuration::GetOutputHeight()
{
	return 480;
}

int Configuration::GetOutputFps()
{
	return 24;
}
