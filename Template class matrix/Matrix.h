#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Matrix {
private:
	int rows;
	int cols;
	T** data;

public:
	Matrix(int rows, int cols);
	~Matrix()

	void fillFromKeyboard();
	void fillWithRandomValues();
	void display();

	Matrix<T> operator+(const Matrix<T>& other);
	Matrix<T> operator-(const Matrix<T>& other);
	Matrix<T> operator*(const Matrix<T>& other);
	Matrix<T> operator/(const Matrix<T>& other);

	T findMaxElement();
};
#include "Matrix.cpp" // Подключаем файл с реализацией методов шаблонного класса Matrix

#endif // MATRIX_H