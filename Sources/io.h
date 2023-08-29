#ifndef IO_H
#define IO_H

#include "square_solver.h"
#include "utilities.h"



/**
@brief  Очистка буфера. Вызывается тогда и только тогда,
когда пользователь ошибается при вводе чисел.
*/
void clear_buffer();

/**
@brief Ввод коэффициентов уравнения.
@param coeffs коэффициенты уравнения
*/
void input_coeffs (Coeffs* coeffs);

/**
@brief Вывод результата работы программы, в случае, когда число корней уравнения равно двум.
@param x1 первый корень
@param x2 второй корень
*/
void output_complex_roots (Complex x1, Complex x2);

/**
@brief Вывод результата работы программы или вызов complex_output, если число корней
исходного уравнения равно 2. Если корней не 2,функция самостоятельно выводит
на экран решения уравнения. Последний printf просто печатает смайлик.
@param n_roots число корней
@param x1 первый корень
@param x2 второй корень
*/
void output_roots (enum RootsNumber nRoots, Complex x1, Complex x2);

#endif
