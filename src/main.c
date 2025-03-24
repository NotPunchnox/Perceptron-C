#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sigmoid.h"

// Fonction pour initialiser les poids et le biais ( random entre -1 et 1 )
void init_weights(double *w1, double *w2, double *bias) {
    *w1 = (rand() % 2000 - 1000) / 1000.0; 
    *w2 = (rand() % 2000 - 1000) / 1000.0;
    *bias = (rand() % 2000 - 1000) / 1000.0;
}

// Fonction de propagation avant
double predict(double input1, double input2, double w1, double w2, double bias) {
    double sum_weights = input1 * w1 + input2 * w2 + bias;
    return sigmoid(sum_weights);
}

// Fonction de rétropropagation pour ajuster les poids
void train(double input1, double input2, double target, double *w1, double *w2, double *bias, double learning_rate) {
    // Calcul de la prédiction
    double output = predict(input1, input2, *w1, *w2, *bias);

    // Calcul de l'erreur
    double error = target - output;

    // Calcul de la dérivée de l'erreur par rapport aux poids et biais
    double out_deriv = sigmoid_deriv(output);
    double error_u = error * out_deriv;

    // Mise à jour des poids et du biais
    *w1 += learning_rate * error_u * input1;
    *w2 += learning_rate * error_u * input2;
    *bias += learning_rate * error_u;
}

int main(int argc, char *argv[]) {
    // Initialisation des variables ( random )
    srand(time(NULL));

    // Initialisation des poids et du biais
    double w1, w2, bias;
    init_weights(&w1, &w2, &bias);

    // Taux d'apprentissage
    double learning_rate = 0.1;

    // Données d'entraînement ( binaire )
    double inputs[4][2] = {
        {0.0, 0.0},
        {0.0, 1.0},
        {1.0, 0.0},
        {1.0, 1.0}
    };
    
    double targets[4] = {0.0, 1.0, 1.0, 0.0};

    // Entraînement du perceptron (x10000)
    for (int epoch = 0; epoch < 10000; epoch++) {
        for (int i = 0; i < 4; i++) {
            // Entraînement avec toutes les données
            train(inputs[i][0], inputs[i][1], targets[i], &w1, &w2, &bias, learning_rate);
        }
    }

    // Tester le perceptron après l'entraînement
    printf("Prédictions après entraînement:\n");
    for (int i = 0; i < 4; i++) {
        double output = predict(inputs[i][0], inputs[i][1], w1, w2, bias);
        printf("Entrée: %.1f, %.1f | Sortie prédite: %.4f\n", inputs[i][0], inputs[i][1], output);
    }

    return 0;
}
