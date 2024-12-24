#include <iostream>
#include <cmath>
#include <corecrt_math_defines.h>

// Function declarations
double N(double x);
double BSCallPrice(double S, double K, double T, double r, double q, double v);
double BSPutPrice(double S, double K, double T, double r, double q, double v);

// Function definitions
double N(double x) {
    return 0.5 * erfc(-x * M_SQRT1_2);
}

double BSCallPrice(double S, double K, double T, double r, double q, double v) {
    double d1 = (log(S / K) + (r - q + 0.5 * v * v) * T) / (v * sqrt(T));
    double d2 = d1 - v * sqrt(T);
    return S * exp(-q * T) * N(d1) - K * exp(-r * T) * N(d2);
}

double BSPutPrice(double S, double K, double T, double r, double q, double v) {
    double d1 = (log(S / K) + (r - q + 0.5 * v * v) * T) / (v * sqrt(T));
    double d2 = d1 - v * sqrt(T);
    return K * exp(-r * T) * N(-d2) - S * exp(-q * T) * N(-d1);
}

int main() {
    // Example parameters
    double S = 100.0;  // Spot price
    double K = 100.0;  // Strike price
    double T = 1.0;    // Time to maturity in years
    double r = 0.05;   // Risk-free interest rate
    double q = 0.02;   // Dividend yield
    double v = 0.2;    // Volatility

    // Calculate the Black-Scholes call and put prices
    double callPrice = BSCallPrice(S, K, T, r, q, v);
    double putPrice = BSPutPrice(S, K, T, r, q, v);

    // Output the results
    std::cout << "The Black-Scholes call price is: " << callPrice << std::endl;
    std::cout << "The Black-Scholes put price is: " << putPrice << std::endl;

    return 0;
}