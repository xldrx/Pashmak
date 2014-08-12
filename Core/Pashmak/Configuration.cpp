#include "Configuration.h"

Configuration::Configuration()
{
}

Configuration::~Configuration()
{
}

std::string Configuration::addr;

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

void Configuration::SetOverlayVideo(std::string addr){
    Configuration::addr = addr;
}

std::string Configuration::GetOverlayVideo(){
    return Configuration::addr;
}