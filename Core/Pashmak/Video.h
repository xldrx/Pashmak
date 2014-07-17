#pragma once
#include "Media.h"
#include "Picture.h"
#include <opencv2/opencv.hpp>

class Video :
	public Media
{
public:
	Video();
	~Video();

	virtual bool GetNextFrame(std::shared_ptr<Picture>& frame) = 0;
};

