#include<iostream>
#include<Windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

// Создайте шаблонный класс матрица.Необходимо реализовать 
// динамическое выделение памяти, очистку памяти,заполнение
// матрицы с клавиатуры, заполнение случайными значениями,
// отображение матрицы, арифметические операции с помощью
// перегруженных операторов (+, –, *, / ),
// поиск максимального элемента.

template <typename T>
class Matrix {
    int rows;
    int cols;
    T** data;
public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new T * [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void fillFromKeyboard() {
        std::cout << "Введите элементы матрицы:" << std::endl;
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
                data[i][j] = rand() % 99;
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

    Matrix<T> operator+(const Matrix<T>& other) {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    
    Matrix<T>operator-(const Matrix<T>& other)
    {
        Matrix<T> subtraction(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                subtraction.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return subtraction;
    }

    Matrix<T> operator*(const Matrix<T>& other)
    {
        Matrix<T> multiplication(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                multiplication.data[i][j] = data[i][j] * other.data[i][j];
            }
        }
        return multiplication;
    }

    Matrix<T> operator/(const Matrix<T>& other)
    {
        Matrix<T> division(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                division.data[i][j] = data[i][j] / other.data[i][j];
            }
        }
        return division;
    }

    T findMaxElement() {
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
};

int main()
{
	SetConsoleOutputCP(1251);

    Matrix<int> matrix1(2, 2);
    Matrix<int> matrix2(2, 2);

    cout << "Заполняем первую матрицу:" << endl;
    matrix1.fillFromKeyboard();

    cout << "Заполняем вторую матрицу случайными значениями:" <<endl;
    matrix2.fillWithRandomValues();

    cout << "Первая матрица:" << endl;
    matrix1.display();
    cout << "Вторая матрица:" << endl;
    matrix2.display();

    Matrix<int> sumMatrix = matrix1 + matrix2;
    cout << "Сумма матриц:" << endl;
    sumMatrix.display();

    int maxElement = matrix1.findMaxElement();
    cout << "Максимальный элемент в первой матрице: " << maxElement << endl;

	return 0;
}