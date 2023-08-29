#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#include "tests.h"
#include "utilities.h"
#include "square_solver.h"
#include "io.h"

/* snake_style

PascalStyle

camelStyle

UPPERCASE_STYLE   */


/**
@brief Функция, решающая уравнение для комплексных чисел. Вызывается только если
дискриминант отрицательный (то есть мнимая часть точно не равна нулю).
@param coeffs
@param x1  решение уравнения
@param x2  решение уравнения
@param D дискриминант квадратного уравнения
@return Количество корней уравнения.
*/
static enum RootsNumber solve_complex_equation (Coeffs* coeffs, const double D, Complex* x1, Complex* x2);

static enum RootsNumber solve_complex_equation (Coeffs* coeffs, const double D, Complex* x1, Complex* x2)
{

    const double sqrt_D = sqrt(-D);

    if (compare_double (coeffs->b, 0))
    {
        x1->real = 0;
        x2->real = 0;

        x1->imagine = +sqrt_D / (2 * fabs (coeffs->a));
        x2->imagine = -x1->imagine;
    }
    else
    {
        x1->real    = -coeffs->b / (2*coeffs->a);
        x1->imagine = +sqrt_D / (2 * fabs (coeffs->a));

        x2->real    =  x1->real;
        x2->imagine = -x1->imagine;
    }

    return TWO_ROOTS;
}

/**
@brief Функция, решающая линейное уравнение. Вызывается только если
старший коэффициент равен нулю.
@param coeffs
@param x1  решение уравнения
@return Количество корней уравнения.
*/
static enum RootsNumber solve_linear_equation (Coeffs* coeffs, Complex* x1);

static enum RootsNumber solve_linear_equation (Coeffs* coeffs, Complex* x1)
{
    assert (isfinite (x1->real));

    if (compare_double (coeffs->b, 0))
    {
        if (compare_double (coeffs->c, 0))
        {
            return INF_ROOTS;
        }

        else
        {
            return ZERO_ROOTS;
        }
    }

    else
    {
        if (compare_double (coeffs->c, 0))
        {
            x1->real = 0;
        }
        else
        {
            x1->real = -coeffs->c/coeffs->b;
        }
        return ONE_ROOT;
    }
}

enum RootsNumber solve_square_equation (Coeffs coeffs, Complex* x1, Complex* x2)
{
    double a = coeffs.a;
    double b = coeffs.b;
    double c = coeffs.c;
    if (compare_double (a, 0))
    {
        return solve_linear_equation (&coeffs, x1);
    }

    else if (compare_double (b, 0))
    {
        if (a*c > 0)
        {
            const double D = -4*a*c; //дискриминант
            return (solve_complex_equation (&coeffs, D, x1, x2));
        }
        else
        {
            x1->real = sqrt (fabs (-c/a));
            if (!compare_double (x1->real, 0))
            {
                x2->real = -(x1->real);
                return TWO_ROOTS;
            }
            return ONE_ROOT;
        }
    }

    else if (compare_double (c, 0))
    {
        x2->real = 0;
        x1->real = -b/a;
        return TWO_ROOTS;
    }

    else
    {
        const double D = coeffs.b*coeffs.b - 4*coeffs.a*coeffs.c;

        if (compare_double (D, 0))
        {
            x1->real = -coeffs.b / (2*coeffs.a);
            return ONE_ROOT;
        }
        else if (D > 0)
        {
            double sqrt_D = sqrt(D); //корень дискриминанты
            x1->real = (-coeffs.b + sqrt_D) / (2*coeffs.a);
            x2->real = (-coeffs.b - sqrt_D) / (2*coeffs.a);
            return TWO_ROOTS;
        }
        else
        {
            return (solve_complex_equation (&coeffs, D, x1, x2));
        }
    }
}


