cmake_minimum_required( VERSION 2.8 )
project( OclDeepLearning )

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

#find_package( OpenCL REQUIRED )

#include_directories( ${OPENCL_INCLUDE_DIRS} )


add_subdirectory(lib)
add_subdirectory(test)
add_subdirectory(tools)

#TODO add docs subdirectory
