#include "../headers/tests.h"
#include "../headers/matrix.h"
#include <iostream>

using namespace std;

void firstConstructorTest()
{
    cout << "test: constructor with n, m and defaultElement as params \n";
    Matrix m1(4, 3, 1);
    cout << m1.toString();
    cout << "\n\n";
}

void secondConstructorTest()
{
    cout << "test: constructor with VectorOfVector as params \n";
    Matrix m2({{1, 2}, {4, 5}, {6, 7}});
    cout << m2.toString() << "\n";
    cout << "n: " << m2._n() << " m: " << m2._m();
    cout << "\n\n";
}

void matrixAdditionTest()
{
    cout << "test: Matrix operator+ overload \n";
    Matrix m3(3, 4, 1), m4(3, 4, 2);
    Matrix m5 = m3 + m4;
    cout << m3.toString() << "\n"
         << m4.toString() << "\n";
    cout << m5.toString();
    cout << "\n\n";
}

void minusMatrixTest()
{
    cout << "test: -matrix \n";
    Matrix m6(2, 4, 1);
    Matrix m7 = -m6;
    cout << m7.toString();
    cout << "\n\n";
}

void substractionMatrixTest()
{
    cout << "test: a-b Matrix substration \n";
    Matrix m8(2, 4, 5), m9(2, 4, 2);
    Matrix m10 = m8 - m9;
    cout << m10.toString();
    cout << "\n\n";
}