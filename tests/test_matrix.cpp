/**
 * @file test_matrix.cpp
 * @brief Модульные тесты для класса Matrix
 *
 * Этот файл содержит тесты для проверки корректности работы
 * основных операций над матрицами.
 */

#include <gtest/gtest.h>
#include "../src/Matrix.h"
#include <fstream>

void createTestFile(const std::string &filename, const std::string &content)
{
    std::ofstream file(filename);
    file << content;
    file.close();
}

/**
 * @brief Тест создания матрицы
 */
TEST(MatrixTest, LoadFromFileTest)
{
    std::string filename = "test_matrix.txt";
    createTestFile(filename, "1 2\n3 4");

    Matrix A = Matrix::loadFromFile(filename);
    Matrix expected({{1, 2}, {3, 4}});

    EXPECT_EQ(A, expected);
}

/**
 * @brief Тест операции сложения матриц
 */
TEST(MatrixTest, AdditionFromFileTest)
{
    createTestFile("matrixA.txt", "1 2\n3 4");
    createTestFile("matrixB.txt", "5 6\n7 8");

    Matrix A = Matrix::loadFromFile("matrixA.txt");
    Matrix B = Matrix::loadFromFile("matrixB.txt");

    Matrix expected({{6, 8}, {10, 12}});
    EXPECT_EQ(A + B, expected);
}

/**
 * @brief Тест операции умножения матриц
 */
TEST(MatrixTest, MultiplicationFromFileTest)
{
    createTestFile("matrixA.txt", "1 2\n3 4");
    createTestFile("matrixB.txt", "2 0\n1 2");

    Matrix A = Matrix::loadFromFile("matrixA.txt");
    Matrix B = Matrix::loadFromFile("matrixB.txt");

    Matrix expected({{4, 4}, {10, 8}});
    EXPECT_EQ(A * B, expected);
}

TEST(MatrixTest, DeterminantFromFileTest)
{
    createTestFile("matrixA.txt", "1 2\n3 4");

    Matrix A = Matrix::loadFromFile("matrixA.txt");

    EXPECT_DOUBLE_EQ(A.determinant(), -2.0);
}

TEST(MatrixTest, LoadNonExistentFileTest)
{
    EXPECT_THROW(Matrix::loadFromFile("non_existent.txt"), std::runtime_error);
}

TEST(MatrixTest, LoadEmptyFileTest)
{
    createTestFile("empty_matrix.txt", "");

    EXPECT_THROW(Matrix::loadFromFile("empty_matrix.txt"), std::runtime_error);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
