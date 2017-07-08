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

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
 
int main(void) {
    // Create black empty images
    Mat image = Mat::zeros(400, 400, CV_8UC3);

    // Draw a line
    // We are making a copy of image because we don't want to draw all the shapes on one image
    Mat imageLine = image.clone();
    line(imageLine, Point(15, 20), Point(370, 350), Scalar(110, 220, 0), 5, CV_AA);
    imshow("line", imageLine);

    // Draw a circle
    Mat imageCircle = image.clone();
    circle(imageCircle, Point(200, 200), 50.0, Scalar(0, 0, 255), 2, 8);
    imshow("circle", imageCircle);

    // Draw an ellipse
    Mat imageEllipse = image.clone();
    ellipse(imageEllipse, Point(200, 200), Size(100.0, 160.0), 45, 0, 360, Scalar(255, 0, 0), 1, 8);
    ellipse(imageEllipse, Point(200, 200), Size(100.0, 160.0), 135, 0, 360, Scalar(255, 0, 0), 10, 8);
    ellipse(imageEllipse, Point(200, 200), Size(150.0, 50.0), 135, 0, 360, Scalar(0, 255, 0), 1, 8);
    imshow("ellipse", imageEllipse);

    // Draw a rectangle (5th argument is not -ve)
    Mat imageRectangle = image.clone();
    rectangle(imageRectangle, Point(15, 20), Point(115, 120), Scalar(0, 55, 255), +1, 4 );
    imshow("rectangle1", imageRectangle);
    // Draw a filled rectangle (5th argument is -ve)
    rectangle(imageRectangle, Point(125, 135), Point(225, 235), Scalar(100, 155, 25), -1, 8);
    imshow("rectangle2", imageRectangle);

    // Draw a filled Polygon
    Mat imagePolygon = image.clone();
    int w = 400;
    /** Create some points */
    Point rookPoints[1][20];
    rookPoints[0][0] = Point(w/4.0, 7*w/8.0);
    rookPoints[0][1] = Point(3*w/4.0, 7*w/8.0);
    rookPoints[0][2] = Point(3*w/4.0, 13*w/16.0);
    rookPoints[0][3] = Point(11*w/16.0, 13*w/16.0);
    rookPoints[0][4] = Point(19*w/32.0, 3*w/8.0);
    rookPoints[0][5] = Point(3*w/4.0, 3*w/8.0);
    rookPoints[0][6] = Point(3*w/4.0, w/8.0);
    rookPoints[0][7] = Point(26*w/40.0, w/8.0);
    rookPoints[0][8] = Point(26*w/40.0, w/4.0);
    rookPoints[0][9] = Point(22*w/40.0, w/4.0);
    rookPoints[0][10] = Point(22*w/40.0, w/8.0);
    rookPoints[0][11] = Point(18*w/40.0, w/8.0);
    rookPoints[0][12] = Point(18*w/40.0, w/4.0);
    rookPoints[0][13] = Point(14*w/40.0, w/4.0);
    rookPoints[0][14] = Point(14*w/40.0, w/8.0);
    rookPoints[0][15] = Point(w/4.0, w/8.0);
    rookPoints[0][16] = Point(w/4.0, 3*w/8.0);
    rookPoints[0][17] = Point(13*w/32.0, 3*w/8.0);
    rookPoints[0][18] = Point(5*w/16.0, 13*w/16.0);
    rookPoints[0][19] = Point(w/4.0, 13*w/16.0);

    const Point* ppt[1] = {rookPoints[0]};
    int npt[] = {20};
    //Fill the polygon formed by the points 
    fillPoly(imagePolygon, ppt, npt, 1, Scalar(255, 255, 255), 8);
    imshow("Image", imagePolygon);

    // Put text into image
    Mat imageText = image.clone();
    putText(imageText, "OpenCV Basics", Point(100,180), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 200, 200), 4);
    imshow("text", imageText);

    waitKey(0);
    return 0;
}