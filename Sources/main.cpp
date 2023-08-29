#include <stdio.h>
#include <string.h>
#include <math.h>

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

int main(int argc, char* argv[])
{
    struct Coeffs coeffs = {NAN, NAN, NAN};
    struct Complex x1    = {NAN, NAN};
    struct Complex x2    = {NAN, NAN};
    char str[7] = "--test";

    if (argc > 1 && strcmp(argv[1], str) == 0)
        test_all();
    else
    {
        input_coeffs (&coeffs);
        enum RootsNumber n_roots = solve_square_equation (&coeffs, &x1, &x2);
        output_roots (n_roots, &x1, &x2);
    }

    return 0;
}

