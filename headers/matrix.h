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
    int dotProduct(Vector a, Vector b);

public:
    Matrix(int n, int m, int defaultElement);
    Matrix(VectorOfVector matrix);
    string toString();
    int &_n();
    int &_m();
    Matrix operator+(Matrix &matrix);
    Matrix operator-(Matrix &matrix);
    Matrix operator-();
    Matrix operator*(int scalar);
    friend Matrix operator*(int scalar, Matrix &matrix);
    Matrix operator*(Matrix &matrix);
    bool operator==(Matrix &a);
    Vector getLine(int i);
    Vector getColumn(int i);
    Matrix transpose();
    //minorMatrix() //lapalce
    // det
    //++
    //--
    // cout <<
    //[]
    //[][]
    // cramerMatrix(Matrix, Vector, int)
    // cramerSolver(Matrix, Vector)
    // switch to templates instead of int
    // make polynome class
};