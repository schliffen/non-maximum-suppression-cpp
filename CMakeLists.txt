cmake_minimum_required (VERSION 3.5)

# Setup projectname
project (nms VERSION 1.0.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -ldl")
# Compile and link main.cpp and foo.cpp


set(OPENCV_INCLUDE_DIR /home/ali/installations/opencv/include/opencv4)
set(OPENCV_LIB_DIR /home/ali/installations/opencv/lib)
set(CMAKE_PREFIX_PATH /home/ali/installations/opencv/lib/cmake/opencv4)

find_package( OpenCV REQUIRED )


include_directories( include )
include_directories( weights )

add_library( nmslib
    SHARED
    include/nms.cpp
    include/nms.hpp
    include/utils.cpp
    include/utils.hpp
)


INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

link_directories(${OpenCV_LIBS})

add_executable( ${PROJECT_NAME} example.cpp )

target_link_libraries(  ${PROJECT_NAME}  nmslib  ${OpenCV_LIBS} ) #

