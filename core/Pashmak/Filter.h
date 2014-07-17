#pragma once
#include "Picture.h"
#include <memory>

class Filter
{
public:
	Filter();
	~Filter();

	std::shared_ptr<Picture> Apply(const std::shared_ptr<Picture>& media);

private:
	virtual std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) = 0;
};

