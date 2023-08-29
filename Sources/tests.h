#ifndef TESTS_H
#define TESTS_H

#include "square_solver.h"

/**
@brief Содержит один тест.
*/
struct TestInput
{
    Coeffs coeffs; ///< коэффициенты уравнения
    Complex x1ref; ///< первое решение
    Complex x2ref; ///< второе решение
    int n_rootsref; ///< количество решений
    //const char name[10];
};

/**
@brief Сравнивает корни.
@param x1 первый корень
@param x1ref второй корень
@return true, если корни равны и false, если нет.
*/
bool compare_complex (Complex x1, Complex x1ref);

/**
@brief Проверяет, проходит ли программа тест.
@param coeffs коэффициенты уравнения
@param x1ref первое решение
@param x2ref второе решение
@param n_rootsref число решений
@param test_number номер теста
@return 1, если тест пройден и 0, если нет.
*/
int test_one (TestInput* test_inputs, int test_number);

/**
@brief Подставляет тесты в Test_one и считает, сколько тестов пройдено.
*/
void test_all (char* file_name);


#endif
