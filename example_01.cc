/**
 * This is one of a set of examples for
 * practicing using and building OpenCV
 * code.
 */

#include <iostream>
#include <algorithm>
#include <vector>

int iterator_function(int input)
{
    return 2 * input;
}

int main(int argc, char **argv)
{
    std::cout << "Hello, World!" <<std::endl;
    std::vector<int> vec {{ 1, 2, 3, 4, 5, 6, 7 }};
    std::for_each(vec.begin(), vec.end(), &iterator_function);

    return 0;
}