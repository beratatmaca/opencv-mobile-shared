cmake_minimum_required(VERSION 3.12)

project(ArUcoMarkerDetection)

# Find OpenCV using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(OPENCV REQUIRED opencv4)

# Add the executable
add_executable(aruco_marker_detection main.cpp)
set(CMAKE_BUILD_TYPE Release)
message(${OPENCV_INCLUDE_DIRS})

# Include directories
target_include_directories(aruco_marker_detection PRIVATE ${OPENCV_INCLUDE_DIRS})

# Link the executable with OpenCV
target_link_libraries(aruco_marker_detection PRIVATE ${OPENCV_LIBRARIES})
