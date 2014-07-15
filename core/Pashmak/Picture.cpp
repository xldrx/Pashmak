#include "Picture.h"

Picture::Picture(const cv::Mat& mat)
{
	myMat = mat;
}

Picture::~Picture()
{
}

cv::Mat& Picture::Mat()
{
	return myMat;
}
