# Copyright 2017 BIG VISION LLC ALL RIGHTS RESERVED
# 
# This code is made available to the students of 
# the online course titled "Computer Vision for Faces" 
# by Satya Mallick for personal non-commercial use. 
#
# Sharing this code is strictly prohibited without written
# permission from Big Vision LLC. 
#
# For licensing and other inquiries, please email 
# spmallick@bigvisionllc.com 
#

import cv2
import numpy as np

image = np.zeros((400, 400, 3), dtype=np.uint8)

# Draw a line
# We are making a copy of image because we don't want to draw all the shapes on one image
imageLine = image.copy()
cv2.line(imageLine, (15, 20), (370, 350), (110, 220, 0), thickness=2, lineType=cv2.LINE_AA)
cv2.imshow("line", imageLine)

# Draw a circle
imageCircle = image.copy()
cv2.circle(imageCircle, (200, 200), 50, (0, 0, 255), thickness=2, lineType=cv2.LINE_AA)
cv2.imshow("circle", imageCircle)

# Draw an ellipse
# IMP Note: Ellipse Centers and Axis lengths must be integers
imageEllipse = image.copy()
cv2.ellipse(imageEllipse, (200, 200), (100, 160), 45, 0, 360, (255, 0, 0), thickness=2, lineType=cv2.LINE_AA)
cv2.ellipse(imageEllipse, (200, 200), (100, 160), 135, 0, 360, (0, 0, 255), thickness=5, lineType=cv2.LINE_AA)
cv2.ellipse(imageEllipse, (200, 200), (150, 50), 135, 0, 360, (0, 255, 0), thickness=2, lineType=cv2.LINE_AA)
cv2.imshow("ellipse", imageEllipse)

# Draw a rectangle (thickness is a positive integer)
imageRectangle = image.copy()
cv2.rectangle(imageRectangle, (105, 105), (205, 205), (0, 55, 255), thickness=+2, lineType=cv2.LINE_8)
cv2.imshow("rectangle1", imageRectangle)
# Draw a filled rectangle (thickness is a negative integer)
cv2.rectangle(imageRectangle, (210, 210), (310, 310), (100, 155, 25), thickness=-1, lineType=cv2.LINE_8)
cv2.imshow("rectangle2", imageRectangle)

# Draw a filled Polygon
imagePolygon = image.copy()
w = 400
# Create some points
rookPoints = np.zeros((1, 20, 2))
rookPoints[0, 0, :] = (w/4.0, 7*w/8.0)
rookPoints[0, 1, :] = (3*w/4.0, 7*w/8.0)
rookPoints[0, 2, :] = (3*w/4.0, 13*w/16.0)
rookPoints[0, 3, :] = (11*w/16.0, 13*w/16.0)
rookPoints[0, 4, :] = (19*w/32.0, 3*w/8.0)
rookPoints[0, 5, :] = (3*w/4.0, 3*w/8.0)
rookPoints[0, 6, :] = (3*w/4.0, w/8.0)
rookPoints[0, 7, :] = (26*w/40.0, w/8.0)
rookPoints[0, 8, :] = (26*w/40.0, w/4.0)
rookPoints[0, 9, :] = (22*w/40.0, w/4.0)
rookPoints[0, 10, :] = (22*w/40.0, w/8.0)
rookPoints[0, 11, :] = (18*w/40.0, w/8.0)
rookPoints[0, 12, :] = (18*w/40.0, w/4.0)
rookPoints[0, 13, :] = (14*w/40.0, w/4.0)
rookPoints[0, 14, :] = (14*w/40.0, w/8.0)
rookPoints[0, 15, :] = (w/4.0, w/8.0)
rookPoints[0, 16, :] = (w/4.0, 3*w/8.0)
rookPoints[0, 17, :] = (13*w/32.0, 3*w/8.0)
rookPoints[0, 18, :] = (5*w/16.0, 13*w/16.0)
rookPoints[0, 19, :] = (w/4.0, 13*w/16.0)

# fillPoly expects data points to be in int32 format
ppt = np.int32(np.around(rookPoints))

#Fill polygon formed by the points
cv2.fillPoly(imagePolygon, ppt, (255, 255, 255), lineType=cv2.LINE_8)
cv2.imshow("Image", imagePolygon)

# Put text into image
imageText = image.copy()
cv2.putText(imageText, "OpenCV Basics", (100, 180), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 200, 100), 4)
cv2.imshow("text", imageText)

cv2.waitKey(0)

cv2.destroyAllWindows()