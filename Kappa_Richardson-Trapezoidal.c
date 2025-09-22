#include <stdio.h>
#include <math.h>

// Function to integrate: f(x) = e^x
double f(double x) {
    return exp(x);
}

// Trapezoidal Rule implementation
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));


