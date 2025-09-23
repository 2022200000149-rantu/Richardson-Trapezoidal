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
// Rantu

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
//Haider

int main() {
    double a, b;
    int n;

    // Show formulas before taking input
    printf("\n");
    printf("   Richardson Extrapolation with Trapezoidal Rule\n");
    printf("\n");
    printf("Trapezoidal Rule Formula:\n");
    printf("   T(h) = (h/2) * [ f(a) + 2*Σ f(a+i*h) + f(b) ]\n");
    printf("where h = (b-a)/n\n\n");
    //ratul

    printf("Richardson Extrapolation Formula:\n");
    printf("   I ≈ (4*T(h/2) - T(h)) / 3\n\n");

    printf("Function to integrate: f(x) = e^x\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    // Take user input
    printf("Enter lower limit (a): ");
    scanf("%lf", &a);
    printf("Enter upper limit (b): ");
    scanf("%lf", &b);
    printf("Enter number of subintervals (n): ");
    scanf("%d", &n);
//Sahil
    

    if (n <= 0) {
        printf("Number of subintervals must be positive!\n");
        return 1;
    }

    // Compute approximations
    double trap = trapezoidal(a, b, n);
    double extrap = richardson(a, b, n);
    double exact = exp(b) - exp(a); // true integral of e^x from a to b

    // Print results
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("   Results\n");
    //Chumki


printf("   Integral of e^x from %.2f to %.2f\n", a, b);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Method                     Approximation           Error\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("Trapezoidal (n=%d)           %14.10f       %.5e\n", n, trap, fabs(trap - exact));
    printf("Richardson  Extrapolation   %14.10f       %.5e\n", extrap, fabs(extrap - exact));
    printf("Exact Value                 %14.10f\n", exact);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    return 0;
}
//Raihan














