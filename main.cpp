#include <stdio.h>
#include <string.h>

#include "tests.h"
#include "utilities.h"
#include "square_solver.h"
#include "io.h"

//-----------------------------------------------
/**
@mainpage Программа для решения квадратных уравнений
Состоит из следующих частей:
- @ref main.cpp
- @ref square_solver.cpp
- @ref io.cpp
- @ref tests.cpp
- @ref utilities.cpp
*/
//-----------------------------------------------

/**
@brief Основная функция, в которой начинается и заканчивается программа.
@param argc
@param argv[]
@return Результат работы программы и, если этого попросит пользователь, тесты.
*/
int main(int argc, char* argv[])
{
    struct Coeffs coeffs = {0, 0, 0};
    struct Complex x1    = {0, 0};
    struct Complex x2    = {0, 0};

    input(&coeffs);
    enum RootsNumber nRoots = Solver (coeffs, &x1, &x2);
    output (nRoots, x1, x2);

    if (argc > 1 && strcmp(argv[1], "--test") == 0)
        TestAll();
    return 0;
}
