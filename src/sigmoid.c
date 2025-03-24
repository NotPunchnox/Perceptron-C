#include <math.h>

// Fonction sigmoïde et sa dérivée
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_deriv(double x) {
    return x * (1.0 - x);
}