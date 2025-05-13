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
#include <vector>

Matrix parseMatrixFromString(const std::string &str)
{
    std::istringstream iss(str);
    int rows, cols;
    iss >> rows >> cols;

    std::vector<std::vector<double>> data(rows, std::vector<double>(cols));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!(iss >> data[i][j]))
            {
                throw std::runtime_error("Неверный формат данных матрицы");
            }
        }
    }
    return Matrix(data);
}

void printUsage()
{
    std::cout << "Использование: main_app \"rows cols matrix1_data\" \"rows cols matrix2_data\"" << std::endl;
    std::cout << "Пример: main_app \"2 2 1 2 3 4\" \"2 2 5 6 7 8\"" << std::endl;
}

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
        if (argc != 3)
        {
            printUsage();
            return 1;
        }

        Matrix A = parseMatrixFromString(argv[1]);
        Matrix B = parseMatrixFromString(argv[2]);

        std::cout << "Матрица A:" << std::endl;
        A.display();
        std::cout << "\nМатрица B:" << std::endl;
        B.display();

        std::cout << "\nA + B:" << std::endl;
        (A + B).display();
        std::cout << "\nA * B:" << std::endl;
        (A * B).display();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
