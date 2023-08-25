#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generator(int Count)
{
    while (Count>0)
    {
        srand(time(NULL));
        double a = rand()%20-10;
        double b = rand()%20-10;
        double c = rand()%20-10;
        double d = rand()%20-10;
        // (ax-b)(cx-d) = ac*x^2 - (bc+ad)x + bd; x1 = b/a, x2 = d/c
        printf("%lg %lg %lg %lg %d %lg %d %d", a*c, -(b*c+a*d), b*d, b/a, 0, c/d, 0, 2);
        Count -= 1;
    }
}

int main()
{
    srand(time(NULL));
    double a = rand()%200-100;
    double b = rand()%200-100;
    double c = rand()%200-100;
    double d = rand()%200-100;
    // (ax-b)(cx-d) = ac*x^2 - (bc+ad)x + bd; x1 = b/a, x2 = d/c
    printf("%lg, %lg, %lg, %lg, %d, %lg, %d, %d\n", a*c, -(b*c+a*d), b*d, b/a, 0, d/c, 0, 2);
    for (int i = 0; i < 10000; ++i)
    {
    a = rand()%200-100;
    b = rand()%200-100;
    c = rand()%200-100;
    d = rand()%200-100;
    // (ax-b)(cx-d) = ac*x^2 - (bc+ad)x + bd; x1 = b/a, x2 = d/c
    if (a != 0 and c != 0)
    printf("%lg, %lg, %lg, %lg, %d, %lg, %d, %d\n", a*c, -(b*c+a*d), b*d, b/a, 0, d/c, 0, 2);
    }
}
