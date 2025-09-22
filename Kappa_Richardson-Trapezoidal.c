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

   for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    return h * sum;
}

// Richardson Extrapolation applied to Trapezoidal Rule
double richardson(double a, double b, int n) {
    double T_h = trapezoidal(a, b, n);       // step h
    double T_h2 = trapezoidal(a, b, 2 * n);  // step h/2
    return (4 * T_h2 - T_h) / 3.0;
}


