cmake_minimum_required(VERSION 3.25)
project(mouse_input)


set(OpenCV_DIR /usr/local/Cellar/opencv/4.8.0_1/lib/cmake/opencv4/OpenCVConfig.cmake)
# Find OpenCV package
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 17)

find_library(ApplicationServices ApplicationServices)
find_library(CoreFoundation CoreFoundation)



add_executable(mouse_input main.cpp mouse.cpp mouse.h keyboard.cpp keyboard.h system_operations.cpp system_operations.h image_recognition.cpp image_recognition.h program.cpp program.h)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Link OpenCV libraries

# Find the required frameworks and libraries


# Link the frameworks and libraries
target_link_libraries(mouse_input ${ApplicationServices} ${CoreFoundation} ${OpenCV_LIBS})