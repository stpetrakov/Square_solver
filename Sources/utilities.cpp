#include <math.h>
#include <assert.h>

#include "square_solver.h"
#include "utilities.h"

void swap(double *a, double *b)
{
    assert (a);
    assert (b);
    const double save = *b; //временно хранит значение b
    *b = *a;
    *a = save;

}

void sort_struct (Complex* x1, Complex* x2)
{
    assert (x1);
    assert (x2);

    if (x1->real < x2->real)
        swap ( &x1->real, &x2->real);

    if (x1->imagine < x2->imagine)
        swap (&x1->imagine, &x2->imagine);
}

bool compare_double (double first, double second)
{
    const double EPSILON = 1e-5;  //допустимая погрешность
    return (fabs (first - second) < EPSILON);
}
