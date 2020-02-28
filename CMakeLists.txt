cmake_minimum_required(VERSION 3.0.0)
project(GISClouds VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(opencv_basic_load_example opencv_basic_load_example.cc)
add_executable(geographiclib_local_cartesian_example geographiclib_local_cartesian_example.cc)
add_executable(pcl_kdtree_example pcl_kdtree_example.cc)
add_executable(pcl_convert_io_example pcl_convert_io_example.cc)

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
    target_link_libraries(opencv_basic_load_example ${PCL_LIBRARIES})
    target_link_libraries(geographiclib_local_cartesian_example ${PCL_LIBRARIES})
    target_link_libraries(pcl_kdtree_example ${PCL_LIBRARIES})
    target_link_libraries(pcl_convert_io_example ${PCL_LIBRARIES})
endif (PCL_FOUND)

include_directories(/usr/local/include)
find_library(Geographic_LIBRARY Geographic)
target_link_libraries(opencv_basic_load_example ${Geographic_LIBRARY})
target_link_libraries(geographiclib_local_cartesian_example ${Geographic_LIBRARY})
target_link_libraries(pcl_kdtree_example ${Geographic_LIBRARY})
target_link_libraries(pcl_convert_io_example ${Geographic_LIBRARY})

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
