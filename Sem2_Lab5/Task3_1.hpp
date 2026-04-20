#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class Matrix {
private:
    T** data;
    size_t rows;
    size_t cols;

public:
    Matrix(size_t r, size_t c);
    Matrix(const Matrix& other);
    ~Matrix();
    Matrix& operator=(const Matrix& other);

    void Set(size_t i, size_t j, const T& value);
    T Get(size_t i, size_t j) const;

    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator*(const Matrix<T>& other) const;

    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    // Дружественные операторы ввода/вывода
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& mat);
    template<typename U>
    friend std::istream& operator>>(std::istream& is, Matrix<U>& mat);
};

#include "Matrix_impl.hpp"

#endif
