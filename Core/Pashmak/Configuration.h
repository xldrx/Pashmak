#pragma once
class Configuration
{
public:
	Configuration();
	~Configuration();

	static int GetOutputWidth();
	static int GetOutputHeight();
	static int GetOutputFps();
};

