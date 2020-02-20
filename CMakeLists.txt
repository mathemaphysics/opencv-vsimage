cmake_minimum_required(VERSION 3.0.0)
project(opencv_testing VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(opencv_testing main.cc)
add_executable(localcartesian localcartesian.cc)

find_package(OpenCV)
if (OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    target_link_libraries(opencv_testing ${OpenCV_LIBRARIES})
endif (OpenCV_FOUND)

include_directories(/usr/local/include)
find_library(TileDB_LIBRARY tiledb)
target_link_libraries(opencv_testing ${TileDB_LIBRARY})

find_package(GDAL)
if (GDAL_FOUND)
    include_directories(${GDAL_INCLUDE_DIRS})
    target_link_libraries(opencv_testing ${GDAL_LIBRARIES})
endif (GDAL_FOUND)

include_directories(/usr/local/include)
find_library(Geographic_LIBRARY Geographic)
target_link_libraries(localcartesian ${Geographic_LIBRARY})

set(IMAGE_FILENAME "${CMAKE_SOURCE_DIR}/share/nice_place.jpg")
configure_file(opencv_testing_config.h.in "${CMAKE_SOURCE_DIR}/opencv_testing_config.h")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
