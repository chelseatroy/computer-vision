cmake_minimum_required(VERSION 2.8.12)

PROJECT(week1)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Since there are a lot of examples we will use a macro
# to simply this CMakeLists.txt file.
MACRO(add_example name)
   ADD_EXECUTABLE(${name} ${name}.cpp)
   TARGET_LINK_LIBRARIES(${name} ${OpenCV_LIBS} )
ENDMACRO()


add_example(closing)
add_example(datatypeConversion)
add_example(dilate)
add_example(erode)
add_example(getAffine)
add_example(highguiKeyboard)
add_example(highguiMouse)
add_example(imageDraw)
add_example(opening)
add_example(readWriteDisplay)
add_example(cropAndResize)
add_example(rotate)
add_example(thresholding)
add_example(trackbar)
add_example(videoRead)
add_example(videoWrite)
add_example(warpAffine)