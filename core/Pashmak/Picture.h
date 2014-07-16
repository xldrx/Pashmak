#pragma once
#include <opencv2/opencv.hpp>
#include "Media.h"

class Picture :
	public Media
{
private:
	cv::Mat myMat;

public:
	Picture(const cv::Mat& mat);
	~Picture();

	cv::Mat& Mat();
};

