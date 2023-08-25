#include <math.h>

#include "square_solver.h"
#include "utilities.h"

void Swap(double *a, double *b)
{
    const double save = *b; //временно хранит значение b
    b = a;
    *a = save;

}

void Max_struct (Complex* x1, Complex* x2)
{
    if (x1->real < x2->real)
        Swap( &x1->real, &x2->real);

    if (x1->imagine < x2->imagine)
        Swap (&x1->imagine, &x2->imagine);
}

bool Compare_double (double first, double second)
{
    const double EPSILON = 1e-5;  //допустимая погрешность
    return (fabs (first - second) < EPSILON);
}
