#include "../headers/matrix_tools.h"
#include "../headers/matrix.h"

bool MatrixTools::multipliable(Matrix &a, Matrix &b)
{
    return a._m() == b._n();
}