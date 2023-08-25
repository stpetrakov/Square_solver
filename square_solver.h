#ifndef SOLVER_H
#define SOLVER_H

/**
@brief Количество решений уравнения.
*/
enum RootsNumber
{
    INF_ROOTS = -1,
    ZERO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
};

/**
@brief Содержит коэффициенты квадратного уравнения.
*/
struct Coeffs
{
    double a; ///< коэффициент a
    double b;
    double c;
};

/**
@brief Две части икса (реальная и мнимая).
*/
struct Complex
{
    double real;
    double imagine;
};


/**
@brief Функция, решающая уравнение для комплексных чисел. Вызывается только если
дискриминант отрицательный (то есть мнимая часть точно не равна нулю).
@param coeffs
@param x1  решение уравнения
@param x2  решение уравнения
@param D дискриминант квадратного уравнения
@return Количество корней уравнения.
*/
enum RootsNumber Solve_complex_equation (Coeffs coeffs, const double D, Complex* x1, Complex* x2);


/**
@brief Функция, решающая линейное уравнение. Вызывается только если
старший коэффициент равен нулю.
@param coeffs
@param x1  решение уравнения
@return Количество корней уравнения.
*/
enum RootsNumber Solve_Linear_equation (Coeffs coeffs, Complex* x1);

/**
@brief Функция, решающая уравнение.
@param coeffs
@param x1  решение уравнения
@param x2  решение уравнения
@return Количество корней уравнения.
*/
enum RootsNumber Solver (Coeffs coeffs, Complex* x1, Complex* x2);


#endif
