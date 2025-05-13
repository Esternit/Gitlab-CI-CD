/**
 * @file Matrix.h
 * @brief Заголовочный файл класса Matrix для работы с матрицами
 */

#pragma once

#include <vector>
#include <string>

/**
 * @class Matrix
 * @brief Класс для работы с матрицами
 *
 * Этот класс предоставляет основные операции над матрицами,
 * включая сложение, вычитание, умножение и другие матричные операции.
 */
class Matrix
{
private:
    std::vector<std::vector<double>> data; ///< Данные матрицы
    int rows;                              ///< Количество строк
    int cols;                              ///< Количество столбцов

public:
    /**
     * @brief Конструктор матрицы
     * @param r Количество строк
     * @param c Количество столбцов
     */
    Matrix(int r, int c);
    Matrix(std::vector<std::vector<double>> values);

    /**
     * @brief Получить элемент матрицы
     * @param i Индекс строки
     * @param j Индекс столбца
     * @return Значение элемента
     */
    double get(int i, int j) const;

    /**
     * @brief Установить значение элемента матрицы
     * @param i Индекс строки
     * @param j Индекс столбца
     * @param value Новое значение
     */
    void set(int i, int j, double value);

    /**
     * @brief Получить количество строк
     * @return Количество строк
     */
    int getRows() const;

    /**
     * @brief Получить количество столбцов
     * @return Количество столбцов
     */
    int getCols() const;

    /**
     * @brief Сложение матриц
     * @param other Вторая матрица
     * @return Результат сложения
     */
    Matrix add(const Matrix &other) const;

    /**
     * @brief Вычитание матриц
     * @param other Вторая матрица
     * @return Результат вычитания
     */
    Matrix subtract(const Matrix &other) const;

    /**
     * @brief Умножение матриц
     * @param other Вторая матрица
     * @return Результат умножения
     */
    Matrix multiply(const Matrix &other) const;

    /**
     * @brief Преобразование матрицы в строку
     * @return Строковое представление матрицы
     */
    std::string toString() const;

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
