#pragma once
#include "Media.h"
#include <opencv2/opencv.hpp>

class Picture :
	public Media
{
private:
	cv::Mat myMat;

public:
	Picture(const cv::Mat& mat);
	Picture(const std::string& filename);
	~Picture();

	cv::Mat& Mat();
};

