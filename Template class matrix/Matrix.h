#pragma once
#include<iostream>
#include<Windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T_T>
class Matrix {
    int rows;
    int cols;
    T_T** data;
public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new T_T * [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T_T[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void fillFromKeyboard() {
        cout << "Введите элементы матрицы:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    void fillWithRandomValues() {
        srand((unsigned)time(NULL));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = rand() % 66;
            }
        }
    }

    void display() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix<T_T> operator+(const Matrix<T_T>& other) {
        Matrix<T_T> addition(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                addition.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return addition;
    }

    Matrix<T_T> operator-(const Matrix<T_T>& other)
    {
        Matrix<T_T> subtraction(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                subtraction.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return subtraction;
    }

    Matrix<T_T> operator*(const Matrix<T_T>& other)
    {
        Matrix<T_T> multiplication(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                multiplication.data[i][j] = data[i][j] * other.data[i][j];
            }
        }
        return multiplication;
    }

    Matrix<T_T> operator/(const Matrix<T_T>& other)
    {
        Matrix<T_T> division(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                division.data[i][j] = data[i][j] / other.data[i][j];
            }
        }
        return division;
    }

    T_T findMaxElement() {
        T_T maxElement = data[0][0];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] > maxElement) {
                    maxElement = data[i][j];
                }
            }
        }
        return maxElement;
    }
};