/*
Copyright 2017 BIG VISION LLC ALL RIGHTS RESERVED

This code is made available to the students of 
the online course titled "Computer Vision for Faces" 
by Satya Mallick for personal non-commercial use. 

Sharing this code is strictly prohibited without written
permission from Big Vision LLC. 

For licensing and other inquiries, please email 
spmallick@bigvisionllc.com 
*/

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <cmath>
#include <vector>

using namespace cv;
using namespace std;

int main(void)
{
// Read image
Mat source = imread("../../data/images/lena.jpg",1);
source.at<Vec3b>(50,50)[0]=0;
source.at<Vec3b>(50,50)[1]=255;
source.at<Vec3b>(50,50)[2]=0;
source.at<Vec3b>(50,49)[0]=0;
source.at<Vec3b>(50,49)[1]=255;
source.at<Vec3b>(50,49)[2]=0;
source.at<Vec3b>(50,51)[0]=0;
source.at<Vec3b>(50,51)[1]=255;
source.at<Vec3b>(50,51)[2]=0;
source.at<Vec3b>(51,50)[0]=0;
source.at<Vec3b>(51,50)[1]=255;
source.at<Vec3b>(51,50)[2]=0;
source.at<Vec3b>(49,50)[0]=0;
source.at<Vec3b>(49,50)[1]=255;
source.at<Vec3b>(49,50)[2]=0;
source.at<Vec3b>(49,49)[0]=0;
source.at<Vec3b>(49,49)[1]=255;
source.at<Vec3b>(49,49)[2]=0;
source.at<Vec3b>(49,51)[0]=0;
source.at<Vec3b>(49,51)[1]=255;
source.at<Vec3b>(49,51)[2]=0;
source.at<Vec3b>(51,51)[0]=0;
source.at<Vec3b>(51,51)[1]=255;
source.at<Vec3b>(51,51)[2]=0;
source.at<Vec3b>(51,49)[0]=0;
source.at<Vec3b>(51,49)[1]=255;
source.at<Vec3b>(51,49)[2]=0;
source.at<Vec3b>(140,180)[0]=0;
source.at<Vec3b>(140,180)[1]=255;
source.at<Vec3b>(140,180)[2]=0;
source.at<Vec3b>(139,180)[0]=0;
source.at<Vec3b>(139,180)[1]=255;
source.at<Vec3b>(139,180)[2]=0;
source.at<Vec3b>(141,180)[0]=0;
source.at<Vec3b>(141,180)[1]=255;
source.at<Vec3b>(141,180)[2]=0;
source.at<Vec3b>(140,181)[0]=0;
source.at<Vec3b>(140,181)[1]=255;
source.at<Vec3b>(140,181)[2]=0;
source.at<Vec3b>(140,179)[0]=0;
source.at<Vec3b>(140,179)[1]=255;
source.at<Vec3b>(140,179)[2]=0;
source.at<Vec3b>(139,179)[0]=0;
source.at<Vec3b>(139,179)[1]=255;
source.at<Vec3b>(139,179)[2]=0;
source.at<Vec3b>(141,179)[0]=0;
source.at<Vec3b>(141,179)[1]=255;
source.at<Vec3b>(141,179)[2]=0;
source.at<Vec3b>(141,181)[0]=0;
source.at<Vec3b>(141,181)[1]=255;
source.at<Vec3b>(141,181)[2]=0;
source.at<Vec3b>(139,181)[0]=0;
source.at<Vec3b>(139,181)[1]=255;
source.at<Vec3b>(139,181)[2]=0;
source.at<Vec3b>(200,150)[0]=0;
source.at<Vec3b>(200,150)[1]=255;
source.at<Vec3b>(200,150)[2]=0;
source.at<Vec3b>(201,150)[0]=0;
source.at<Vec3b>(201,150)[1]=255;
source.at<Vec3b>(201,150)[2]=0;
source.at<Vec3b>(199,150)[0]=0;
source.at<Vec3b>(199,150)[1]=255;
source.at<Vec3b>(199,150)[2]=0;
source.at<Vec3b>(201,149)[0]=0;
source.at<Vec3b>(201,149)[1]=255;
source.at<Vec3b>(201,149)[2]=0;
source.at<Vec3b>(200,149)[0]=0;
source.at<Vec3b>(200,149)[1]=255;
source.at<Vec3b>(200,149)[2]=0;
source.at<Vec3b>(199,149)[0]=0;
source.at<Vec3b>(199,149)[1]=255;
source.at<Vec3b>(199,149)[2]=0;
source.at<Vec3b>(200,151)[0]=0;
source.at<Vec3b>(200,151)[1]=255;
source.at<Vec3b>(200,151)[2]=0;
source.at<Vec3b>(201,151)[0]=0;
source.at<Vec3b>(201,151)[1]=255;
source.at<Vec3b>(201,151)[2]=0;
source.at<Vec3b>(199,151)[0]=0;
source.at<Vec3b>(199,151)[1]=255;
source.at<Vec3b>(199,151)[2]=0;

line(source, Point2f(51,51), Point2f(179,139), Scalar(255,0,0), 1, 8,0);
line(source, Point2f(181,141), Point2f(149,199), Scalar(255,0,0), 1, 8,0);
line(source, Point2f(51,51), Point2f(149,201), Scalar(255,0,0), 1, 8,0);
imshow("points",source);

// Create mask/ warp matrix
Mat warpMat = (Mat_<double>(2,3) << 1.2, 0.2, 2, -0.3, 1.3, 1 );

// Another mask
Mat warpMat2 = (Mat_<double>(2,3) << 1.2, 0.3, 2, 0.2, 1.3, 1);

Mat result,result2;
// Use warp affine
cv::warpAffine(source, result, warpMat, Size(1.5*source.rows,1.4*source.cols), INTER_LINEAR, BORDER_REFLECT_101);
cv::warpAffine(source, result2, warpMat2, Size(1.5*source.rows, 1.4*source.cols), INTER_LINEAR, BORDER_REFLECT_101);
// Display images
imshow("Original", source);
imshow("Result", result);
imshow("Result2", result2);
waitKey(0);
}