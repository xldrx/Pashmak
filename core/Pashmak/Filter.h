#pragma once
#include "Media.h"
#include <memory>

class Filter
{
public:
	Filter();
	~Filter();

	virtual std::shared_ptr<Media> Apply(const std::shared_ptr<Media>& media) = 0;
};

