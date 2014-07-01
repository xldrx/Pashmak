Mat GuassianWindow(Mat src)
{
    Mat Channel[3];
    Mat buff;
    src.convertTo(buff, CV_64FC3);
    split(buff, Channel);
    
    Mat a = getGaussianDist(src.size());
    multiply(Channel[0], a, Channel[0]);
    multiply(Channel[1], a, Channel[1]);
    multiply(Channel[2], a, Channel[2]);
    merge(Channel,3,buff);
    return buff;
}