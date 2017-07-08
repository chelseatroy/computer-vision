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

imageName = "../../data/images/opening.png"
# Image taken as input
image = cv2.imread(imageName, cv2.IMREAD_GRAYSCALE)

# Check for invalid input
if image is None:  
    print("Could not open or find the image")

# Get structuring element/kernel which will be used for opening operation
openingSize = 3

# Selecting a elliptical kernel
element = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (2 * openingSize + 1, 2 * openingSize + 1),(openingSize,openingSize))

# Applying erosion followed by dilation on image by using morphologyEx function and specifying MORPH_OPEN tag(denotes opening operation)
imageMorphOpened = cv2.morphologyEx(image, cv2.MORPH_OPEN, element,iterations=3)

# Display the original image
cv2.namedWindow("Original Image", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Original Image", image)		

# Image after morphological opening operation
cv2.namedWindow("Opening", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Opening",imageMorphOpened)		

# Wait for user to press any key
cv2.waitKey(0)
cv2.destroyAllWindows()
