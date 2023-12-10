#include<iostream>
#include<Windows.h>
#include"Matrix.h"


using namespace std;

// Создайте шаблонный класс матрица.Необходимо реализовать 
// динамическое выделение памяти, очистку памяти,заполнение
// матрицы с клавиатуры, заполнение случайными значениями,
// отображение матрицы, арифметические операции с помощью
// перегруженных операторов (+, –, *, / ),
// поиск максимального элемента.

int main()
{
	SetConsoleOutputCP(1251);

    // Создаем матрицы с типом int
    Matrix<int> matrix1(2, 2);
    Matrix<int> matrix2(2, 2);

    // Заполняем первую матрицу с клавиатуры
    cout << "Fill in the first matrix:" << endl;
    matrix1.();

    // Заполняем вторую матрицу случайными значениями
    cout << "Fill in the second matrix with random values:" <<endl;
    matrix2.fillWithRandomValues();

    // Выводим обе матрицы на экран
    cout << "First matrix:" << endl;
    matrix1.display();
    cout << "Second matrix:" << endl;
    matrix2.display();

    // Выполняем сложение матриц
    Matrix<int> sumMatrix = matrix1 + matrix2;
    cout << "Sum of matrices:" << endl;
    sumMatrix.display();

    // Находим максимальный элемент в первой матрице
    int maxElement = matrix1.findMaxElement();
    cout << "Max element in the first matrix: " << maxElement << endl;





   // try {
   //     Matrix<double> matrix;
   //     matrix.setMatrix();
   //     matrix.getMatrix();
   // }
   // catch (const exception&) {

   // }
   //// _getch();


	/*Matrix<double> matrix;
	matrix.setMatrix();
	matrix.getMatrix();*/



	return 0;
}