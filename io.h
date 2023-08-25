#ifndef IO_H
#define IO_H

#include "square_solver.h"



/**
@brief  Очистка буфера. Вызывается тогда и только тогда,
когда пользователь ошибается при вводе чисел.
*/
void Clear_buffer();

/**
@brief Ввод коэффициентов уравнения.
@param coeffs
*/
void input (Coeffs* coeffs);

/**
@brief Вывод результата работы программы, в случае, когда числомкорней уравнения равно двум.
@param x1
@param x2
*/
void complex_output (Complex x1, Complex x2);

/**
- @brief Вывод результата работы программы или вызов complex_output, если число корней
исходного уравнения равно 2. Если корней не 2,функция самостоятельно выводит
на экран решения уравнения. Последний printf просто печатает смайлик.
@param nRoots
@param x1
@param x2
*/
void output (enum RootsNumber nRoots, Complex x1, Complex x2);

#endif
