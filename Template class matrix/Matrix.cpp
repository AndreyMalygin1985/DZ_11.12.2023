#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
    data = new T * [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new T[cols];
    }
}

template <typename T>
void Matrix<T>::fillFromKeyboard()
{
    std::cout << "Enter matrix elements:" << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cin >> data[i][j];
        }
    }
}

//template<typename T>
//void Matrixx::Matrix<T>::fillFromKeyboard()
//{
//    std::cout << "Enter matrix elements:" << std::endl;
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < cols; ++j) {
//            std::cin >> data[i][j];
//        }
//    }
//}

template<typename T>
void Matrix<T>::fillWithRandomValues() 
{
    srand(time(0));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            data[i][j] = rand() % 100; // Здесь использованы случайные значения от 0 до 99
        }
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other)
{
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other)
{
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other)
{
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] * other.data[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const Matrix<T>& other)
{
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] / other.data[i][j];
        }
    }
    return result;
}

template<typename T>
void Matrix<T>::display()
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
T Matrix<T>::findMaxElement()
{
    T maxElement = data[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] > maxElement) {
                maxElement = data[i][j];
            }
        }
    }
    return maxElement;
}