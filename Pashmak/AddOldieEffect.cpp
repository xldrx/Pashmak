Mat AddOldieEffect(Mat src)
{
    int LineNumber = 10;
    int a,b,c;
    Mat res;
    res = Mat::zeros(src.size(), src.type());
    srand((unsigned)time(0));
    for (int i=0; i<LineNumber; i++) {
        a = rand() % src.size().height;
        b = rand() % src.size().height;
        c = rand() % src.size().width - 1;
        
        res(Range(min(a,b),max(a,b)), Range(c,c+1)) = Scalar(32,32,32);
    }
    c = rand() % src.size().width - 1;
    res(Range(0,res.size().height), Range(c,c+1)) = Scalar(32,32,32);
    c = rand() % src.size().width - 1;
    res(Range(0,res.size().height), Range(c,c+1)) = Scalar(32,32,32);
    res += src;
    return res;
    
}