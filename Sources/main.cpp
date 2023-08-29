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
    char str_test[7] = "--test";
    char str_help[7] = "--help";
    char str_t[3] = "-t";
    char str_h[3] = "-h";

    if (argc > 1)
    {
        if (argc == 3 && (strcmp(argv[1], str_test) || strcmp(argv[1], str_t)))
            test_all (argv[2]);

        else
        {
            printf ("Enter coeffs a, b, c of equation a*x^2 + b*x + c\n");
            printf ("Options:\n");
            printf ("--help or -h: Display this information\n");
            printf ("--test or -t: Launches tests from your file\n");
            printf ("You should print -t + file name\n");
        }

    }
    else
    {
        input_coeffs (&coeffs);

        enum RootsNumber n_roots = solve_square_equation (&coeffs, &x1, &x2);
        output_roots (n_roots, &x1, &x2);
    }

    return 0;
}

