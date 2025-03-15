#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
    data.resize(rows, std::vector<double>(cols, 0));
}

Matrix::Matrix(std::vector<std::vector<double>> values) : data(values)
{
    rows = values.size();
    cols = values.empty() ? 0 : values[0].size();
}

int Matrix::getRows() const { return rows; }
int Matrix::getCols() const { return cols; }

void Matrix::display() const
{
    for (const auto &row : data)
    {
        for (double val : row)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    std::vector<std::vector<double>> values;
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::vector<double> row;
        double value;
        while (ss >> value)
        {
            row.push_back(value);
        }
        if (!row.empty())
            values.push_back(row);
    }

    file.close();

    if (values.empty())
    {
        throw std::runtime_error("Matrix file is empty: " + filename);
    }

    return Matrix(values);
}

Matrix Matrix::operator+(const Matrix &other) const
{
    if (rows != other.rows || cols != other.cols)
    {
        throw std::invalid_argument("Matrices must have the same size.");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

Matrix Matrix::operator-(const Matrix &other) const
{
    if (rows != other.rows || cols != other.cols)
    {
        throw std::invalid_argument("Matrices must have the same size.");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] - other.data[i][j];
    return result;
}

Matrix Matrix::operator*(const Matrix &other) const
{
    if (cols != other.rows)
    {
        throw std::invalid_argument("Number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < other.cols; ++j)
            for (int k = 0; k < cols; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
}

Matrix Matrix::operator/(double scalar) const
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] / scalar;
    return result;
}

double Matrix::determinant() const
{
    if (rows != cols)
        throw std::invalid_argument("Determinant can be calculated only for square matrices.");
    return determinantRecursive(*this);
}

double Matrix::determinantRecursive(const Matrix &matrix)
{
    int n = matrix.getRows();
    if (n == 1)
        return matrix.data[0][0];
    if (n == 2)
        return matrix.data[0][0] * matrix.data[1][1] - matrix.data[0][1] * matrix.data[1][0];

    double det = 0;
    for (int i = 0; i < n; ++i)
    {
        Matrix subMatrix(n - 1, n - 1);
        for (int j = 1; j < n; ++j)
            for (int k = 0, col = 0; k < n; ++k)
                if (k != i)
                    subMatrix.data[j - 1][col++] = matrix.data[j][k];

        det += (i % 2 == 0 ? 1 : -1) * matrix.data[0][i] * determinantRecursive(subMatrix);
    }
    return det;
}

Matrix Matrix::transpose() const
{
    Matrix result(cols, rows);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[j][i] = data[i][j];
    return result;
}

Matrix Matrix::power(int exponent) const
{
    if (rows != cols)
        throw std::invalid_argument("Power can be calculated only for square matrices.");
    Matrix result = *this;
    for (int i = 1; i < exponent; ++i)
    {
        result = result * (*this);
    }
    return result;
}

int Matrix::rank() const
{
    Matrix temp = *this;
    int rank = 0;
    for (int row = 0; row < rows; ++row)
    {
        if (temp.data[row][row] != 0)
        {
            for (int col = 0; col < cols; ++col)
                temp.data[row][col] /= temp.data[row][row];
            for (int i = row + 1; i < rows; ++i)
                for (int j = 0; j < cols; ++j)
                    temp.data[i][j] -= temp.data[row][j] * temp.data[i][row];
            ++rank;
        }
    }
    return rank;
}

bool Matrix::operator==(const Matrix &other) const
{
    if (rows != other.rows || cols != other.cols)
    {
        return false;
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (std::abs(data[i][j] - other.data[i][j]) > 1e-6)
            {
                return false;
            }
        }
    }
    return true;
}