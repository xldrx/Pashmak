Mat ApplyOldieFilter(Mat src)
{
    Mat buff = GuassianWindow(src);
    
    buff = AddGaussianNoise(buff);
    
    buff = AddOldieEffect(buff);
    
    buff = AddSepiaEffect(buff);
    
    buff.convertTo(buff, CV_8U);
    
    return buff;
}