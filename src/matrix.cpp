#include <iostream>
#include <string>
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