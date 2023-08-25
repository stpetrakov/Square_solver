#ifndef TESTS_H
#define TESTS_H

#include "square_solver.h"

/**
@brief Содержит один тест
*/
struct TestInput
{
    Coeffs coeffs; ///< коэффициенты уравнения
    Complex x1ref; ///< первое решение
    Complex x2ref; ///< второе решение
    int nRootsref; ///< количество решений
    //const char name[10];
};

/**
@brief Сравнивает структуры типа Complex
@param x1
@param x1ref
@return true, если структуры равны и false, если нет
*/
bool Compare_complex_struct (Complex x1, Complex x1ref);

/**
@brief Проверяет, проходит ли программа тест
@param coeffs
@param x1ref
@param x2ref
@param nRootsref
@param test_number
@return 1, если тест пройден и 0, если нет
*/
int TestOne (const Coeffs coeffs, const Complex x1ref, const Complex x2ref, const int nRootsref, const int test_number);

/**
@brief Подставляет тесты в TestOne и считает, сколько тестов пройдено
*/
void TestAll ();


#endif
