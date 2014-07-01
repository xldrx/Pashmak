Mat AddGaussianNoise(Mat src)
{
	int Mean = 1;
	int StdDev = 5;
    Mat res;
    res.create(src.size(), src.type());
    randn(res, Mean, StdDev);
    res += src;
    return res;
}