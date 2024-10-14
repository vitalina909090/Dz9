#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

template<typename T>
class Matrix {
private:
    int rows, cols;
    T** mas;

public:
    Matrix() : rows(0), cols(0), mas(nullptr) { }

    Matrix(int Prows, int Pcols) : rows(Prows), cols(Pcols) {
        mas = new T * [rows];
        for (int i = 0; i < rows; i++) {
            mas[i] = new T[cols];
        }
    }

    ~Matrix() {
        if (mas != nullptr) {
            for (int i = 0; i < rows; i++) {
                delete[] mas[i];
            }
            delete[] mas;
        }
    }

    void random() {
        srand(time(0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mas[i][j] = 1 + rand() % (50 - 1 + 1);
            }
        }
    }

    void input() {
        cout << "Введіть у матрицю " << rows * cols << " значень: " << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mas[i][j];
            }
        }
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mas[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mas[i][j] = mas[i][j] + other.mas[i][j];
            }
        }
        return result;
    }
    Matrix operator-(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mas[i][j] = mas[i][j] - other.mas[i][j];
            }
        }
        return result;
    }
    Matrix operator*(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mas[i][j] = mas[i][j] * other.mas[i][j];
            }
        }
        return result;
    }
    Matrix operator/(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mas[i][j] = mas[i][j] / other.mas[i][j];
            }
        }
        return result;
    }

    T maximum() {
        T max = mas[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mas[i][j] > max) {
                    max = mas[i][j];
                }
            }
        }
        return max;
    }
    T minimum() {
        T min = mas[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mas[i][j] < min) {
                    min = mas[i][j];
                }
            }
        }
        return min;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int rows, cols;
    cout << "Введіть кількість рядків: ";
    cin >> rows;
    cout << "Введіть кількість стовпців: ";
    cin >> cols;

    Matrix<int> matrix1(rows, cols);
    Matrix<int> matrix2(rows, cols);

    matrix1.random();
    matrix2.input();

    cout << "Рандомна матриця:" << endl;
    matrix1.print();

    cout << "Ваша матриця:" << endl;
    matrix2.print();

    Matrix<int> example1 = matrix1 + matrix2;
    Matrix<int> example2 = matrix1 - matrix2;
    Matrix<int> example3 = matrix1 * matrix2;
    Matrix<int> example4 = matrix1 / matrix2;
    cout << "Додавання матриць: " << endl;
    example1.print();
    cout << "Віднімання матриць: " << endl;
    example2.print();
    cout << "Множення матриць: " << endl;
    example3.print();
    cout << "Ділення матриць: " << endl;
    example4.print();

    cout << "Максимум в рандомній матриці: " << matrix1.maximum() << endl;
    cout << "Мінімум в вашій матриці: " << matrix2.minimum() << endl;

    return 0;
}
