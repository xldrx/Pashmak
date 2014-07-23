#include "Picture.h"
#include "Configuration.h"

Picture::Picture(const cv::Mat& mat)
{
	myMat = mat;
}

Picture::Picture(const std::string& filename)
{
	cv::resize(cv::imread(filename), myMat, cv::Size(Configuration::GetOutputWidth(), Configuration::GetOutputHeight()));
}

Picture::~Picture()
{
}

cv::Mat& Picture::Mat()
{
	return myMat;
}
