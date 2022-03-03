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
    cout << "n: " << m2._n() << " m: " << m2._m() << "\n";
    cout << "\n\n";
}