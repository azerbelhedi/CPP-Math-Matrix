#include <iostream>
#include <string>
#include <cassert>
#include <math.h>
#include "../headers/matrix.h"
#include "../headers/matrix_tools.h"

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
    assert((n == matrix._n() && m == matrix._m()) && "can't add two matrices with different dimenssions");

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

/*
    getLine() and getColumn() required for this fucntion
*/
Matrix Matrix::operator*(Matrix &matrix)
{
    assert(MatrixTools::multipliable(*this, matrix) && "can't multiply matrices with unvalid dimenssions!");
    Matrix res(n, matrix._m(), 0);
    // zu bearbeiten
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < matrix._m(); j++)
        {
            res.matrix[i][j] = this->dotProduct(this->getRow(i), matrix.getColumn(j));
        }
    }
    return res;
}

bool Matrix::operator==(Matrix &a)
{
    if (n != a._n() || m != a._m())
        return false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] != a.matrix[i][j])
                return false;
        }
    }
    return true;
}

Vector Matrix::getRow(int i)
{
    return matrix[i];
}

Vector Matrix::getColumn(int i)
{
    Vector res(0);
    for (int j = 0; j < n; j++)
    {
        res.push_back(matrix[j][i]);
    }
    return res;
}

int Matrix::dotProduct(Vector a, Vector b)
{
    int res = 0;
    for (int i = 0; i < a.size(); i++)
    {
        res += a[i] * b[i];
    }
    return res;
}

Matrix Matrix::transpose()
{
    Matrix res(m, n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res.matrix[j][i] = matrix[i][j];
        }
    }
    return res;
}

Matrix Matrix::minorMatrix(int row, int column)
{
    // m and n should be bigger than 1
    assert(n > 1 && m > 1 && "can't calculate minor matrix of a vector!\n");
    VectorOfVector resMatrix(0, Vector(0));
    for (int i = 0; i < n; i++)
    {
        if (i != row)
        {
            Vector rowVector(0);
            for (int j = 0; j < m; j++)
            {
                if (j != column)
                {
                    rowVector.push_back(this->matrix[i][j]);
                }
            }
            resMatrix.push_back(rowVector);
        }
    }
    return Matrix(resMatrix);
}

int Matrix::det()
{
    assert(n == m && "can't calculate det of non NxN matrix!\n");
    if (n == 2)
    {
        VectorOfVector matrix = this->matrix;
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    }

    int res = 0;
    for (int j = 0; j < m; j++)
    {
        res += pow(-1, j + 2) * this->matrix[0][j] * (this->minorMatrix(0, j)).det();
    }
    return res;
}

Matrix Matrix::power(int p)
{
    Matrix res = *this;
    for (int i = 1; i < p; i++)
    {
        res = res * *this;
    }
    return res;
}