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

#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat image;
    // Image read in and stored in Mat image
    image = imread("../../data/images/closing.png", IMREAD_GRAYSCALE);

    // Create a structuring element
    int closingSize = 10;
    // Selecting a elliptical kernel and storing in Mat element
    Mat element = getStructuringElement(cv::MORPH_ELLIPSE,cv::Size(2 * closingSize + 1, 2 * closingSize + 1),cv::Point(closingSize, closingSize));     
    // Mat imageMorphClosed stores the image after closing operation
    Mat imageMorphClosed;

    // Applying dilation followed by closing on image by using morphologyEx function and specifying MORPH_CLOSE tag(denotes closing operation) 
    morphologyEx(image, imageMorphClosed, MORPH_CLOSE, element);         
    
    // Display original image
    namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    imshow("Original Image", image);

    // Display the image after morphological closing is done
    namedWindow("Closing", CV_WINDOW_AUTOSIZE);
    imshow("Closing", imageMorphClosed);   

    // Wait for the user to press any key
    waitKey(0);
    return 0;
}
