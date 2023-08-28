#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#include "tests.h"
#include "utilities.h"
#include "square_solver.h"
#include "io.h"

enum RootsNumber Solve_complex_equation (Coeffs coeffs, const double D, Complex* x1, Complex* x2)
{

    const double sqrt_D = sqrt(-D);

    if (Compare_double (coeffs.b, 0))
    {
        x1->real = 0;
        x2->real = 0;

        x1->imagine = +sqrt_D / (2 * fabs (coeffs.a));
        x2->imagine = -x1->imagine;
    }
    else
    {
        x1->real    = -coeffs.b / (2*coeffs.a);
        x1->imagine = +sqrt_D / (2 * fabs (coeffs.a));

        x2->real    =  x1->real;
        x2->imagine = -x1->imagine;
    }

    return TWO_ROOTS;
}

enum RootsNumber Solve_Linear_equation (Coeffs coeffs, Complex* x1)
{
    assert (isfinite (x1->real));
    if (Compare_double (coeffs.c, 0))
    {
        if (Compare_double (coeffs.b, 0))
        {
            return (INF_ROOTS);
        }

        else
        {
            x1->real = 0;
            return ONE_ROOT;
        }
    }

    else
    {
        if (Compare_double (coeffs.b, 0))
        {
            return ZERO_ROOTS;
        }
        else
        {
            x1->real = -coeffs.c/coeffs.b;
        }
        return ONE_ROOT;
    }
}

enum RootsNumber Solver (Coeffs coeffs, Complex* x1, Complex* x2)
{

    if (Compare_double (coeffs.a, 0))
    {
        return Solve_Linear_equation (coeffs, x1);
    }

    else if (Compare_double (coeffs.b, 0))
    {
        if (coeffs.a*coeffs.c > 0)
        {
            const double D = -4*coeffs.a*coeffs.c; //дискриминант
            return (Solve_complex_equation (coeffs, D, x1, x2));
        }
        else
        {
            x1->real = sqrt (fabs (-coeffs.c/coeffs.a));
            if (not Compare_double (x1->real, 0))
            {
                x2->real = -(x1->real);
                return TWO_ROOTS;
            }
            return ONE_ROOT;
        }
    }

    else if (Compare_double (coeffs.c, 0))
    {
        x2->real = 0;
        x1->real = -coeffs.b/coeffs.a;
        return TWO_ROOTS;
    }

    else
    {
        const double D = coeffs.b*coeffs.b - 4*coeffs.a*coeffs.c;

        if (Compare_double (D, 0))
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
            return (Solve_complex_equation (coeffs, D, x1, x2));
        }
    }
}


