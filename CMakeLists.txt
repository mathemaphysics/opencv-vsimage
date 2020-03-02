cmake_minimum_required(VERSION 3.0.0)
project(GISClouds VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_MODULE_PATH $ENV{CMAKE_MODULE_PATH})

add_executable(opencv_basic_load_example opencv_basic_load_example.cc)
add_executable(geographiclib_local_cartesian_example geographiclib_local_cartesian_example.cc)
add_executable(pcl_kdtree_example pcl_kdtree_example.cc)
add_executable(pcl_convert_io_example pcl_convert_io_example.cc)
add_executable(las2pcd las2pcd.cc)

find_package(OpenCV)
if (OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    target_link_libraries(opencv_basic_load_example ${OpenCV_LIBRARIES})
    target_link_libraries(geographiclib_local_cartesian_example ${OpenCV_LIBRARIES})
    target_link_libraries(pcl_kdtree_example ${OpenCV_LIBRARIES})
    target_link_libraries(pcl_convert_io_example ${OpenCV_LIBRARIES})
endif (OpenCV_FOUND)

include_directories(/usr/local/include)
find_library(TileDB_LIBRARY tiledb)
target_link_libraries(opencv_basic_load_example ${TileDB_LIBRARY})
target_link_libraries(geographiclib_local_cartesian_example ${TileDB_LIBRARY})
target_link_libraries(pcl_kdtree_example ${TileDB_LIBRARY})
target_link_libraries(pcl_convert_io_example ${TileDB_LIBRARY})

find_package(GDAL)
if (GDAL_FOUND)
    include_directories(${GDAL_INCLUDE_DIRS})
    target_link_libraries(opencv_basic_load_example ${GDAL_LIBRARIES})
    target_link_libraries(geographiclib_local_cartesian_example ${GDAL_LIBRARIES})
    target_link_libraries(pcl_kdtree_example ${GDAL_LIBRARIES})
    target_link_libraries(pcl_convert_io_example ${GDAL_LIBRARIES})
endif (GDAL_FOUND)

find_package(PCL)
if (PCL_FOUND)
    include_directories(${PCL_INCLUDE_DIRS})
    link_directories(${PCL_INCLUDE_DIRS})
    add_definitions(${PCL_DEFINITIONS})
    target_link_libraries(opencv_basic_load_example ${PCL_LIBRARIES})
    target_link_libraries(geographiclib_local_cartesian_example ${PCL_LIBRARIES})
    target_link_libraries(pcl_kdtree_example ${PCL_LIBRARIES})
    target_link_libraries(pcl_convert_io_example ${PCL_LIBRARIES})
    target_link_libraries(las2pcd ${PCL_LIBRARIES})
endif (PCL_FOUND)

find_package(GeographicLib)
if (GeographicLib_FOUND)
    target_link_libraries(opencv_basic_load_example ${GeographicLib_LIBRARIES})
    target_link_libraries(geographiclib_local_cartesian_example ${GeographicLib_LIBRARIES})
    target_link_libraries(pcl_kdtree_example ${GeographicLib_LIBRARIES})
    target_link_libraries(pcl_convert_io_example ${GeographicLib_LIBRARIES})
endif (GeographicLib_FOUND)

find_package(Boost REQUIRED)
if (Boost_FOUND)
    include_directories(${BOOST_INCLUDE_DIRS})
    link_directories(${BOOST_LIBRARY_DIRS})
    target_link_libraries(las2pcd ${BOOST_LIBRARIES})
endif (Boost_FOUND)

target_link_libraries(las2pcd las)

set(IMAGE_FILENAME "${CMAKE_SOURCE_DIR}/share/nice_place.jpg")
configure_file(gis_cloudage_config.h.in "${CMAKE_SOURCE_DIR}/gis_cloudage_config.h")

#add_test(
#    NAME
#        test1
#    CONFIGURATIONS
#        Debug
#    WORKING_DIRECTORY
#        ${CMAKE_BINARY_DIR}/test
#    COMMAND
#        echo "This is a test"
#)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
