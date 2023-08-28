#ifndef UTILITYES_H
#define UTILITYES_H

#include "square_solver.h"

/**
@brief Меняет значения двух чисел
@param b
@param a
*/
void Swap (double *a, double *b);

/**
@brief Делает x1 больше чем x2
@param x1
@param x2
*/
void Max_struct (Complex* x1, Complex* x2);

/**
@brief Сравнивает два числа
@param first
@param second
@return true, если они равны и false, если нет
*/
bool Compare_double (double first, double second);

#endif
