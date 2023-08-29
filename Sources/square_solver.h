#ifndef SOLVER_H
#define SOLVER_H

/**
@brief Количество решений уравнения.
*/
enum RootsNumber
{
    INF_ROOTS  = -1, ///< бесконечность корней
    ZERO_ROOTS =  0, ///< ноль корней
    ONE_ROOT   =  1, ///< один корень
    TWO_ROOTS  =  2, ///< два корня
};

/**
@brief Содержит коэффициенты квадратного уравнения.
*/
struct Coeffs
{
    double a; ///< коэффициент a
    double b; ///< коэффициент b
    double c; ///< коэффициент c
};

/**
@brief Две части икса (реальная и мнимая).
*/
struct Complex
{
    double real;    ///< реальная часть икса
    double imagine; ///< мнимая часть икса
};




/**
@brief Функция, решающая уравнение.
@param coeffs коэффициенты уравнения
@param x1  решение уравнения
@param x2  решение уравнения
@return Количество корней уравнения.
*/
enum RootsNumber solve_square_equation (Coeffs coeffs, Complex* x1, Complex* x2);


#endif
