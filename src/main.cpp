#include "Matrix.h"
#include <iostream>

int main()
{
    try
    {
        Matrix A = Matrix::loadFromFile("matrix.txt");
        std::cout << "Matrix:" << std::endl;
        A.display();

        std::cout << "Determinant: " << A.determinant() << std::endl;
        std::cout << "Transpose:" << std::endl;
        A.transpose().display();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
