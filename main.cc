/**
 * This is one of a set of examples for
 * practicing using and building OpenCV
 * code.
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include "opencv_testing_config.h"

int iterator_function(int &input)
{
    input = 2 * input;
}

int main(int argc, char **argv)
{
    /**
     * Introduce yourself
     */
    std::cout << "Hello, World!" <<std::endl;
    std::vector<int> vec {{ 1, 2, 3, 4, 5, 6, 7 }};

    /* Before std::for_each */
    std::cout << "After:" << std::endl;
    for (auto itr = vec.begin(); itr < vec.end(); itr++)
        std::cout << *itr << std::endl;

    /* Run std::for_each */
    std::for_each(vec.begin(), vec.end(), &iterator_function);

    /* After std::for_each */
    std::cout << "After:" << std::endl;
    for (auto itr = vec.begin(); itr < vec.end(); itr++)
        std::cout << *itr << std::endl;

    /* Now try something with OpenCV */
    cv::String fname = IMAGE_FILENAME;
    cv::Mat image = cv::imread(fname, CV_LOAD_IMAGE_UNCHANGED);
    cv::Mat imout = image.clone();
    std::cout << imout << std::endl;
    std::cout << "Row 0: " << imout.ptr() << std::endl;
    cv::namedWindow("Image Test", CV_WINDOW_AUTOSIZE);
    cv::imshow("Image Test", image);
    //cv::VideoCapture(1);
    cv::waitKey(0);
    std::cout << "Dimensions: " << image.rows << " and " << image.cols << std::endl;

    /* Something, something, something... Daaaark Siiide */
    return 0;
}