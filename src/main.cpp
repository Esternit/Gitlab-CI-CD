/**
 * @file main.cpp
 * @brief Главный файл программы калькулятора матриц
 *
 * Программа позволяет выполнять основные операции над матрицами:
 * - Сложение
 * - Вычитание
 * - Умножение
 */

#include "Matrix.h"
#include <iostream>
#include <string>
#include <sstream>

/**
 * @brief Точка входа в программу
 * @param argc Количество аргументов командной строки
 * @param argv Массив аргументов командной строки
 * @return Код завершения программы
 */
int main(int argc, char *argv[])
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
