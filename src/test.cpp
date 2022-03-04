#include "../headers/test.h"
#include "../headers/matrix.h"
#include "../headers/tests.h"
#include <iostream>

using namespace std;

void runAllTests()
{
    cout << "running all tests! \n";
    firstConstructorTest();
    secondConstructorTest();
    matrixAdditionTest();
    minusMatrixTest();
    substractionMatrixTest();
    matrixScalarMultiplyTest();
    scalarMatrixMultiplyTest();
    matrixCompareTest();
    multipliableTest();
    getLineAndColumnTest();
    matrixMatrixProductTest();
}
