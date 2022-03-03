#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> Vector;
typedef vector<Vector> VectorOfVector;

class Matrix
{
    int n; // lines
    int m; // columns
    VectorOfVector matrix;

public:
    Matrix(int n, int m, int defaultElement);
    Matrix(VectorOfVector matrix);
    string toString();
    int &_n();
    int &_m();
    Matrix operator+(Matrix &matrix);
    Matrix operator-(Matrix &matrix);
    Matrix operator-();
    // scalar*b
    // b*scalar
    // a*b
    // transpose
    // det
};