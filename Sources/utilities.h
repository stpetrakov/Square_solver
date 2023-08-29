#ifndef UTILITYES_H
#define UTILITYES_H

#include "square_solver.h"

/**
@brief  Очистка буфера. Вызывается тогда и только тогда,
когда пользователь ошибается при вводе чисел.
*/
void clear_buffer();

/**
@brief Меняет значения двух чисел
@param b первое число
@param a второе число
*/
void swap (double *a, double *b);

/**
@brief Делает x1 больше чем x2
@param x1
@param x2
*/
void sort_struct (Complex* x1, Complex* x2);

/**
@brief Сравнивает два числа
@param first первое число
@param second второе число
@return true, если они равны и false, если нет
*/
bool compare_double (double first, double second);

#endif // UTILITYES_H
