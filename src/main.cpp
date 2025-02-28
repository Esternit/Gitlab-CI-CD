#include <iostream>
#include "math_utils.h"

int main()
{
    std::cout << "2 + 3 = " << add(2, 3) << std::endl;
    std::cout << "7 - 4 = " << subtract(7, 4) << std::endl;
    std::cout << "6 * 3 = " << multiply(6, 3) << std::endl;

    try
    {
        std::cout << "8 / 2 = " << divide(8, 2) << std::endl;
        std::cout << "8 / 0 = " << divide(8, 0) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
