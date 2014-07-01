Mat getGaussianDist(Size s)
{
    double sigmaX = s.height/2;      //vertical standard deviation
    double sigmaY = s.width/2;       //horizantal standard deviation

    Mat res = Mat::zeros(s, CV_64F);
    Point Center(s.height/2,s.width/2);     //center point of the window
    
    for (int i=0; i<s.height; i++) {
        for (int j=0; j<s.width; j++) {
            
            // exp(- A/B + C/D)
            
            double A =(i - Center.x)*(i - Center.x);
            double B = (2*sigmaX*sigmaX);
            double C = (j - Center.y)*(j - Center.y);
            double D = (2*sigmaY*sigmaY);
            
            res.at<double>(i,j) = exp(-(A/B + C/D));
        }
    }
    normalize(res, res, 0, 1, CV_MINMAX);
    return res;
}