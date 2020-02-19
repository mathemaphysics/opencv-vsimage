cmake_minimum_required(VERSION 3.0.0)
project(opencv_testing VERSION 0.1.0)

include(CTest)
enable_testing()

#find_library(TILEDB tiledb /usr/lib /usr/local/lib)
find_package(TileDB)
add_library(tiledb INTERFACE)
target_include_directories(tiledb
        INTERFACE
        ${TileDB_INCLUDE_DIRS})
target_link_libraries(tiledb
        INTERFACE
        ${TileDB_LIBS})

find_package(OpenCV)
add_library(opencv INTERFACE)
target_include_directories(opencv
        INTERFACE
        ${OpenCV_INCLUDE_DIRS})
target_link_libraries(opencv
        INTERFACE
        ${OpenCV_LIBS})

add_executable(opencv_testing main.cc)

set(IMAGE_FILENAME "${CMAKE_SOURCE_DIR}/share/nice_place.jpg")
configure_file(opencv_testing_config.h.in "${CMAKE_SOURCE_DIR}/opencv_testing_config.h")

target_link_libraries(opencv_testing 
    PRIVATE 
        opencv
    PRIVATE
        tiledb
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
