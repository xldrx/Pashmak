//
//  main.cpp
//  OpenCV
//
//  Created by Mehran on 6/29/14.
//  Copyright (c) 2014 Mehran. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char * argv[])
{
    Mat a;
    a = imread("/Users/mehranpesteie/Desktop/tile.jpg");
    namedWindow("test",CV_WINDOW_AUTOSIZE);
    imshow("test", a);
    waitKey();
    
    return 0;
}

