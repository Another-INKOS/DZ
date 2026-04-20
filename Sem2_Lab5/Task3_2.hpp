#ifndef MATRIX_IMPL_HPP
#define MATRIX_IMPL_HPP

#include "Matrix.hpp"

template<typename T>
Matrix<T>::Matrix(size_t r, size_t c) : rows(r), cols(c) {
    if (rows == 0 || cols == 0)
        throw std::invalid_argument("Размеры должны быть >0");
    data = new T * [rows];
    for (size_t i = 0; i < rows; ++i) {
        data[i] = new T[cols];
        for (size_t j = 0; j < cols; ++j)
            data[i][j] = T();
    }
}

template<typename T>
Matrix<T>::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new T * [rows];
    for (size_t i = 0; i < rows; ++i) {
        data[i] = new T[cols];
        for (size_t j = 0; j < cols; ++j)
            data[i][j] = other.data[i][j];
    }
}

template<typename T>
Matrix<T>::~Matrix() {
    for (size_t i = 0; i < rows; ++i)
        delete[] data[i];
    delete[] data;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other) {
    if (this == &other) return *this;
    for (size_t i = 0; i < rows; ++i)
        delete[] data[i];
    delete[] data;
    rows = other.rows;
    cols = other.cols;
    data = new T * [rows];
    for (size_t i = 0; i < rows; ++i) {
        data[i] = new T[cols];
        for (size_t j = 0; j < cols; ++j)
            data[i][j] = other.data[i][j];
    }
    return *this;
}

template<typename T>
void Matrix<T>::Set(size_t i, size_t j, const T& value) {
    if (i >= rows || j >= cols) throw std::out_of_range("Index out of range");
    data[i][j] = value;
}

template<typename T>
T Matrix<T>::Get(size_t i, size_t j) const {
    if (i >= rows || j >= cols) throw std::out_of_range("Index out of range");
    return data[i][j];
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    if (rows != other.rows || cols != other.cols)
        throw std::invalid_argument("Matrix sizes mismatch");
    Matrix<T> res(rows, cols);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            res.data[i][j] = data[i][j] + other.data[i][j];
    return res;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    if (cols != other.rows)
        throw std::invalid_argument("Invalid dimensions for multiplication");
    Matrix<T> res(rows, other.cols);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < other.cols; ++j) {
            T sum = T();
            for (size_t k = 0; k < cols; ++k)
                sum = sum + data[i][k] * other.data[k][j];
            res.data[i][j] = sum;
        }
    return res;
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const Matrix<U>& mat) {
    for (size_t i = 0; i < mat.rows; ++i) {
        for (size_t j = 0; j < mat.cols; ++j) {
            os << mat.data[i][j];
            if (j + 1 < mat.cols) os << " ";
        }
        if (i + 1 < mat.rows) os << "\n";
    }
    return os;
}

template<typename U>
std::istream& operator>>(std::istream& is, Matrix<U>& mat) {
    size_t r, c;
    is >> r >> c;
    if (r == 0 || c == 0)
        throw std::invalid_argument("Invalid matrix size");
    Matrix<U> temp(r, c);
    for (size_t i = 0; i < r; ++i)
        for (size_t j = 0; j < c; ++j) {
            U val;
            is >> val;
            temp.Set(i, j, val);
        }
    mat = temp;
    return is;
}

#endif
