#pragma once

#include <vector>
#include <string>

class Matrix
{
private:
    std::vector<std::vector<double>> data;
    int rows, cols;

public:
    Matrix(int rows, int cols);
    Matrix(std::vector<std::vector<double>> values);

    int getRows() const;
    int getCols() const;

    void display() const;
    static Matrix loadFromFile(const std::string &filename);

    Matrix operator+(const Matrix &other) const;
    Matrix operator-(const Matrix &other) const;
    Matrix operator*(const Matrix &other) const;
    Matrix operator/(double scalar) const;
    bool operator==(const Matrix &other) const;

    double determinant() const;
    Matrix inverse() const;
    int rank() const;
    Matrix transpose() const;
    Matrix power(int exponent) const;

    static double determinantRecursive(const Matrix &matrix);
};
