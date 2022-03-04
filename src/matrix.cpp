#include <iostream>
#include <string>
#include <cassert>
#include "../headers/matrix.h"

using namespace std;

Matrix::Matrix(int n, int m, int defaultElement) : n(n), m(m)
{
    matrix = VectorOfVector(n, Vector(m, defaultElement));
}

Matrix::Matrix(VectorOfVector matrix) : matrix(matrix)
{
    n = matrix.size();
    m = matrix[0].size();
}

string Matrix::toString()
{
    string res = "";
    for (VectorOfVector::iterator i = matrix.begin(); i < matrix.end(); i++)
    {
        for (Vector::iterator j = i->begin(); j < i->end(); j++)
        {
            res += to_string(*j) + "\t";
        }
        res += "\n";
    }
    return res;
}

int &Matrix::_n() { return n; }
int &Matrix::_m() { return m; }

Matrix Matrix::operator+(Matrix &matrix)
{
    assert((n == matrix._n() || m == matrix._m()) && "can't add two matrices with different dimenssions");

    Matrix res(n, m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res.matrix[i][j] = this->matrix[i][j] + matrix.matrix[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator-()
{
    Matrix res(n, m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res.matrix[i][j] = -matrix[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator-(Matrix &a)
{
    Matrix res(n, m, 0);
    res = -a + *this;
    return res;
}

Matrix Matrix::operator*(int scalar)
{
    Matrix res(n, m, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res.matrix[i][j] = matrix[i][j] * scalar;
        }
    }
    return res;
}

Matrix operator*(int scalar, Matrix &matrix)
{
    return matrix * scalar;
}

Matrix operator*(Matrix &matrix){

}

