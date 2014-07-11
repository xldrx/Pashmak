#pragma once
#include "Filter.h"
#include "Picture.h"

class PictureFilter :
	public Filter
{
public:
	PictureFilter();
	~PictureFilter();

	std::shared_ptr<Media> Apply(const std::shared_ptr<Media>& media) override;
	virtual std::shared_ptr<Picture> ApplyImpl(const std::shared_ptr<Picture>& pic) = 0;
};

