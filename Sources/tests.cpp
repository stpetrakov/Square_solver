#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "square_solver.h"
#include "utilities.h"
#include "tests.h"


bool Compare_complex_struct (Complex x1, Complex x1ref)
{
    return (Compare_double (x1.real, x1ref.real) &&
            Compare_double (x1.imagine, x1ref.imagine));
}

int TestOne (const TestInput test_inputs, const int test_number)
{
    struct Complex x1 = {0, 0};
    struct Complex x2 = {0, 0};

    int nRoots = Solver (test_inputs.coeffs, &x1, &x2);

    printf("%d) ", test_number);
    if (Compare_complex_struct (x1, test_inputs.x1ref) &&
        Compare_complex_struct (x2, test_inputs.x2ref) &&
        test_inputs.nRootsref == nRoots)
    {
        printf("Test OK\n");
        return 1;
    }
    else
    {
        printf("FAILED: ""x1" " = {%lg %lg}, x2" " = {%lg %lg}, nRoots" " = %d, "
               "expected: x1ref = {%lg %lg}, x2ref = {%lg %lg}, nRootsref = %d\n",
               x1.real, x1.imagine, x2.real, x2.imagine, nRoots,
               test_inputs.x1ref.real, test_inputs.x1ref.imagine, test_inputs.x2ref.real,
               test_inputs.x2ref.imagine, test_inputs.nRootsref);
        return 0;
    }
}

void TestAll()
{
/*
    //                            a  b  c  x1.re     x1.im       x2.re     x2.im     nRref
    TestInput test_inputs[] = { { 1, 2, 1,  -1,        0,         0,         0,        1},
                                { 1, 2, 2,  -1,        1,        -1,        -1,        2},
                                { 9, 8, 7,  -0.444444, 0.761739, -0.444444, -0.761739, 2},
                                { 2, 8, 4,  -0.585786, 0,        -3.41421,   0,        2},
                                { 1, 0, 0,   0,        0,         0,         0,        1},
                                { 1, 0, 1,   0,        1,         0,        -1,        2},
                                { 1, 5, 4,  -1,        0,        -4,         0,        2},
                                {-1, 5,-4,   1,        0,         4,         0,        2},
                                { 0, 0, 1,   0,        0,         0,         0,        0},
                                {-1, 0, 1,   1,        0,        -1,         0,        2},
                                { 0, 0, 0,   0,        0,         0,         0,       -1},
    };
*/
    FILE *tests = fopen ("tests.txt", "r");
    int count_of_tests = 0;//количество тестов
    int testOK = 0;
    fscanf (tests, "%d", &count_of_tests);
    TestInput test_inputs = {};
    for (size_t i = 0; i < count_of_tests; ++i)
    {

        fscanf (tests, "%lg %lg %lg %lg %lg %lg %lg %d", &test_inputs.coeffs.a, &test_inputs.coeffs.b,
        &test_inputs.coeffs.c, &test_inputs.x1ref.real, &test_inputs.x1ref.imagine,
        &test_inputs.x2ref.real, &test_inputs.x2ref.imagine, &test_inputs.nRootsref);
        testOK += TestOne(test_inputs, i+1);
    }
    // char(1) - smile!
    printf("Passed %d test(s) out of %d %c%c%c",
            testOK, count_of_tests, char(1), char(1), char(1));

/*
    int count_of_tests = sizeof(test_inputs) / sizeof(TestInput); // количество тестов
    int testOK = 0; // счётик пройденных тестов
    for (int i = 0; i < count_of_tests; i++)
    {
        TestInput test = test_inputs[i]; //or TestInput *test = test_inputs + i
        testOK += TestOne(test.coeffs, test.x1ref, test.x2ref, test.nRootsref, i+1);
    }

    // char(1) - smile!
    printf("Passed %d test(s) out of %d %c%c%c",
            testOK, count_of_tests, char(1), char(1), char(1));
*/
}
