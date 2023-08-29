#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "utilities.h"
#include "square_solver.h"
#include "io.h"

void clear_buffer()
{
    int x = getchar();
    while (x != '\n' && x != EOF)
        x = getchar();
}

void input_coeffs (Coeffs* coeffs)
{
    assert (coeffs);

    printf ("Enter a, b, c:\n");

    while (scanf ("%lg %lg %lg", &coeffs->a, &coeffs->b, &coeffs->c) != 3)
    {
        printf ("ERROR: expected 3 numbers");
        printf ("Enter a, b, c: \n");

        clear_buffer();
    }
}

void output_complex_roots (Complex* x1, Complex* x2)
{
    assert (x1);
    assert (x2);
    assert (x1 != x2);

         if (compare_double (x1->imagine, 1) && compare_double (fabs (x1->real), 0))
        printf ("x1 = i, "     "x2 = -i"      "\n");

    else if (compare_double (x1->imagine, 1))
        printf ("x1 = %lg+i, " "x2 = %lg-i"   "\n", x1->real,              x2->real             );

    else if (compare_double (fabs (x1->real), 0))
        printf ("x1 = %lgi, "  "x2 = %lgi"    "\n",           x1->imagine,           x2->imagine);

    else if (compare_double (x2->imagine, 0))
        printf ("x1 = %lg, "   "x2 = %lg"     "\n", x1->real,              x2->real             );

    else
        printf ("x1 = %lg+%lgi, x2 = %lg%lgi" "\n", x1->real, x1->imagine, x2->real, x2->imagine);
}

void output_roots (RootsNumber nRoots, Complex* x1, Complex* x2)
{
    assert (x1);
    assert (x2);

    switch (nRoots)
    {
        case ZERO_ROOTS:
            printf ("No roots \n");
            break;

        case ONE_ROOT:
            printf ("x = %lg \n", x1->real);
            break;

        case TWO_ROOTS:
            output_complex_roots (x1, x2);
            break;

        case INF_ROOTS:
            printf ("Any number \n");
            break;

        default:
            printf ("ERROR: got nRoots = %d\n", nRoots);
    }
    printf("%c\n", 2); //смайлик :)
}
