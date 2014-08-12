#pragma once
#include <string>

class Configuration
{
public:
	Configuration();
	~Configuration();
    static std::string addr;
    
    static void SetOverlayVideo(std::string);
    static std::string GetOverlayVideo();
    static int GetOutputWidth();
	static int GetOutputHeight();
	static int GetOutputFps();
    
};

