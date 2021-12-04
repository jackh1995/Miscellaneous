#include <iostream>
#include <cmath>
#define EPSILON 1.0e-6

using namespace std;

// This is the function to differentiate and/or integrate
double unknown_func(double x) {
    return exp(x) * sin(x);
}

// Finite difference
double differentiate(function<double (double)> func, double x) {
    return (func(x + EPSILON) - func(x)) / EPSILON;
}

// Left Reimann Sum
double integrate(function<double (double)> func, double beg, double end, unsigned n, bool derivative=false) {
    double anchor = beg;
    double dx = (end - beg) / static_cast<double>(n);
    double result(0.0);
    for (int i=0; i!=n; ++i) {
        if (derivative)
            result += differentiate(func, anchor) * dx;
        else    
            result += func(anchor) * dx;
        anchor += dx;
    }
    return result;
}

int main() {
    // Fundamental theorem of Calculus
    cout << integrate(unknown_func, 0, 1, 100000, true) << endl;
    cout << unknown_func(1) - unknown_func(0) << endl;
    return 0;
}
