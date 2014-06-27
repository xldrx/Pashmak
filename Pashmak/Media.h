#pragma once
#include <memory>
#include <string>

class Media
{
public:
	Media();
	~Media();

	void Append(const std::shared_ptr<Media> media);
};

