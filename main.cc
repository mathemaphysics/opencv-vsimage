/**
 * This is one of a set of examples for
 * practicing using and building OpenCV
 * code.
 */

#include <iostream>
#include <algorithm>
#include <vector>

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

    /* Something, something, something... Daaaark Siiide */
    return 0;
}