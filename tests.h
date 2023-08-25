#ifndef TESTS_H
#define TESTS_H

#include "square_solver.h"


struct TestInput
{
    Coeffs coeffs;
    Complex x1ref;
    Complex x2ref;
    int nRootsref;
    //const char name[10];
};

int Compare_complex_struct   (Complex x1, Complex x1ref);
int TestOne                  (const Coeffs coeffs, Complex x1ref, Complex x2ref, const int nRootsref, const int test_number);
void TestAll                 ();

#endif
