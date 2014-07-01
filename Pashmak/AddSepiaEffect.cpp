Mat AddSepiaEffect(Mat src)
{
    Mat res(src.size(),src.type());
    Mat SepiaKernel = (Mat_<float>(4,3) <<  0.200, 0.169, 0.593, \
                                            0.268, 0.086, 0.949, \
                                            0.231, 0.134, 0.972, \
                                            0.000, 0.000, 0.000 );
    transform(src, res, SepiaKernel);
    return res;
    
}