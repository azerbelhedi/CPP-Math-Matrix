#include "../headers/tests.h"
#include "../headers/matrix.h"
#include "../headers/matrix_tools.h"
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

void matrixScalarMultiplyTest()
{
    cout << "test: M*a \n";
    Matrix m11(4, 5, 2);
    Matrix m12 = m11 * 3;
    cout << m12.toString();
    cout << "\n\n";
}

void scalarMatrixMultiplyTest()
{
    cout << "test: a*M \n";
    Matrix m13(2, 4, 5);
    Matrix m14 = 4 * m13;
    cout << m14.toString();
    cout << "\n\n";
}

void matrixCompareTest()
{
    cout << "test: compare two matrices: \n";
    Matrix m15(4, 3, 1), m16(4, 3, 1), m17(4, 3, 2), m18(3, 4, 1);
    cout << (m15 == m16 ? "true" : "false") << " (expected: true)\n";
    cout << (m15 == m17 ? "true" : "false") << " (expected: fasle)\n";
    cout << (m15 == m18 ? "true" : "false") << " (expected: false)\n";
    cout << "\n\n";
}

void multipliableTest()
{
    cout << "test: checks if two matrices are multipliable: \n";
    Matrix m19(3, 5, 1), m20(5, 2, 1), m21(3, 5, 1);
    cout << (MatrixTools::multipliable(m19, m20) ? "true" : "false") << " (expected: true) \n";
    cout << (MatrixTools::multipliable(m20, m19) ? "true" : "false") << " (expected: false) \n";
    cout << (MatrixTools::multipliable(m19, m21) ? "true" : "false") << " (expected: false) \n";
    cout << "\n\n";
}

void getLineAndColumnTest()
{
    cout << "test: get line from matrix: \n";
    Matrix m22({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}});
    Vector line = m22.getRow(1);
    cout << "expected: 4 5 6 \ngot: ";
    for (Vector::iterator i = line.begin(); i < line.end(); i++)
    {
        cout << to_string(*i) << " ";
    }
    cout << "\n";

    cout << "test: get column from matrix: \n";
    Vector column = m22.getColumn(1);
    cout << "expected: 2 5 8 11 \ngot: ";
    for (Vector::iterator i = column.begin(); i < column.end(); i++)
    {
        cout << to_string(*i) << " ";
    }
    cout << "\n\n";
}

void matrixMatrixProductTest()
{
    cout << "test: matrix*matrix: \n";
    Matrix m23({{3, 5, -1}, {4, -8, 2}});
    Matrix m24({{0, 3, 1}, {6, 5, 0}, {2, -7, 3}});
    Matrix expectedMatrix({{28, 41, 0}, {-44, -42, 10}});
    Matrix m25 = m23 * m24;

    // this line is supposed to produce an error
    // Matrix m26 = m24 * m23;
    cout << "result: \n"
         << m25.toString()
         << "\n";
    cout << "expected: \n"
         << expectedMatrix.toString();
    cout << "\n\n";
}

void transposeTest()
{
    cout << "test: matrix transpose: \n";
    Matrix m26({{1, 2, 3}, {4, 5, 6}});
    Matrix m27 = m26.transpose();
    cout << m26.toString() << "\n\n"
         << m27.toString();
    cout << "\n\n";
}

void minorMatrixTest()
{
    cout << "test: minor matrix:\n";
    Matrix m28({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Matrix m29 = m28.minorMatrix(0, 2);
    Matrix expectedMatrix({{4, 5}, {7, 8}});
    cout << "result:\n"
         << m29.toString() << "\nexpected:\n"
         << expectedMatrix.toString();
    cout << "\n\n";
}

void detMatrixTest()
{
    cout << "test: matrix det:\n";
    Matrix m30({{1, 2}, {3, 4}});
    Matrix m31({{1, 5, 9}, {-12, 49, 6}, {2, 3, 8}});
    Matrix m32({{0, 1, 0, 0, 0},
                {0, 2, 1, 0, 2},
                {0, 0, 0, 3, 0},
                {-2, 0, 0, 0, 0},
                {0, 3, 2, 0, 1}});
    Matrix m33({{0, 1, 0, 0},
                {0, 2, 1, 0},
                {0, 0, 0, 3},
                {-2, 0, 0, 0}});
    cout << "result: " << m30.det() << " (expected: -2)\n";
    cout << "result: " << m31.det() << " (expected: -292)\n";
    cout << "result: " << m33.det() << " (expected: 6)\n";
    cout << "result: " << m32.det() << " (expected: -18)\n";
    cout << "\n\n";
}

void powerMatrixTest()
{
    cout << "test: matrix power(2):\n";
    Matrix m33({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Matrix m34 = m33.power(3);
    Matrix expectedMatrix({{468, 576, 684}, {1062, 1305, 1548}, {1656, 2034, 2412}});
    cout << "result:\n"
         << m34.toString() << "\nexpected:\n"
         << expectedMatrix.toString();
    cout << "\n\n";
}