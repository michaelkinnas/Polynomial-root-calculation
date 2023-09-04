# Polynomial root calculation algorithms in C

This collection contains four algorithms for calculating the roots of polynomials.

## Running the algorithms
The code is written in C so you will need to compile them using a gcc compiler.

If you are compling on Linux you must provide the `-lm` argument when you are using the gcc command.

In each file there is a section commented as `//FUNCTIONS GO HERE` before a C function: `double f(double x)` where you put your mathematical functions you want to calculate. The C function `f` must return only one mathematical function. (You can see the examples in the code).

In the `main` function you must provide a left and a right limit for the x values with the variables `a` and `b`, as well as an error precision with the `prec` variable.

## Fixed point iteration method
https://en.wikipedia.org/wiki/Fixed-point_iteration

## False position (Regular Falsi) method
https://en.wikipedia.org/wiki/Regula_falsi


## Bisection method
https://en.wikipedia.org/wiki/Bisection_method

## Newton's method

https://en.wikipedia.org/wiki/Newton%27s_method


