#include<iostream>
#include<Windows.h>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"

//using namespace std;

// Создайте шаблонный класс матрица.Необходимо реализовать 
// динамическое выделение памяти, очистку памяти,заполнение
// матрицы с клавиатуры, заполнение случайными значениями,
// отображение матрицы, арифметические операции с помощью
// перегруженных операторов (+, –, *, / ),
// поиск максимального элемента.

int main()
{
	SetConsoleOutputCP(1251);

    Matrix<double> matrix1(3, 3);
    Matrix<double> matrix2(3, 3);

    cout << "Заполняем первую матрицу:" << endl;
    matrix1.fillFromKeyboard();

    cout << "Заполняем вторую матрицу случайными значениями:" <<endl;
    matrix2.fillWithRandomValues();

    cout << "Первая матрица:" << endl;
    matrix1.display();
    cout << "Вторая матрица:" << endl;
    matrix2.display();

    Matrix<double> sumMatrix = matrix1 + matrix2;
    cout << "Сумма матриц:" << endl;
    sumMatrix.display();

    Matrix<double> diffMatrix = matrix1 - matrix2;
    cout << "Из Первой матрицы вычитаем Вторую:" << endl;
    diffMatrix.display();

    Matrix<double> multMatrix = matrix1 * matrix2;
    cout << "Произведение двух матриц:" << endl;
    multMatrix.display();

    Matrix<double> divMatrix = matrix1 / matrix2;
    cout << "Разделили Первую матрицу на Вторую матрицу:" << endl;
    divMatrix.display();

    int maxElement = matrix1.findMaxElement();
    cout << "Максимальный элемент в первой матрице: " << maxElement << endl;

	return 0;
}