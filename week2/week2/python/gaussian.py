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

import cv2,argparse
import numpy as np

ap = argparse.ArgumentParser()
ap.add_argument("-f", "--filename")
args = vars(ap.parse_args())

filename = "../../data/images/noisyLena.jpg"
if args['filename']:
	filename = args['filename']

img = cv2.imread(filename)

# Apply gaussian blur
dst1=cv2.GaussianBlur(img,(5,5),0,0)
dst2=cv2.GaussianBlur(img,(5,5),5,5)

lineType=4
fontScale=1

cv2.putText(img, "Original Image", (50,50), cv2.FONT_HERSHEY_SIMPLEX, 
            fontScale, (10, 200, 200), lineType)
cv2.putText(dst1, "Smoothened Image", (50,50), cv2.FONT_HERSHEY_SIMPLEX, 
            fontScale, (10, 200, 200), lineType)
cv2.putText(dst2, "Too Smooth due to higher sigma",(50,50), cv2.FONT_HERSHEY_SIMPLEX, 
            0.8, (10, 200, 200), lineType)

# Display images

combined = np.hstack((img, dst1,dst2))
cv2.namedWindow("Original Image   --   Gaussian Blur Results", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Original Image   --   Gaussian Blur Results",combined)

cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imwrite("results/gaussianBlur0.jpg", dst1)
cv2.imwrite("results/gaussianBlur5.jpg", dst2)