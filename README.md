# Premier Perceptron en C

Ce projet implémente un perceptron simple C, il utilise une fonction d'activation sigmoïde. L'objectif est d'apprendre à résoudre la porte logique XOR en entraînant le perceptron avec un ensemble de données binaires.
Ce projet est mon premier essai avec les réseaux de neurones en C.


# Logique de l'opérateur XOR ( table de vérité )

| Entrée A | Entrée B | Sortie (A XOR B) |
|:--------:|:--------:|:----------------:|
|    0     |    0     |        0         |
|    0     |    1     |        1         |
|    1     |    0     |        1         |
|    1     |    1     |        0         |

## Table des matières

- [Introduction](#introduction)
- [Prérequis](#prérequis)
- [Explication du Code](#explication-du-code)
- [Utilisation](#utilisation)
- [Licence](#licence)

## Introduction

Un perceptron est un modèle de réseau de neurones très simple composé d'une seule couche de neurones. Ce programme implémente un perceptron avec une fonction d'activation sigmoïde pour résoudre la porte logique XOR, qui est un problème classique pour tester les réseaux de neurones.

L'objectif principal du projet est d'explorer les bases des réseaux de neurones et de comprendre leur fonctionnement, notamment l'initialisation des poids, la propagation avant, et la rétropropagation et tout ça écrit en C pour changer du Python.


## Prérequis

- Un compilateur C (par exemple, GCC)
- Une bibliothèque math pour la fonction sigmoïde (intégrée dans `math.h`)

## Explication du Code

Le programme comprend les éléments suivants :

1. **Initialisation des poids et du biais** :
   - Les poids (`w1`, `w2`) et le biais sont initialisés de manière aléatoire dans la fonction `init_weights()` avec des valeurs comprises entre -1 et 1.

2. **Propagation avant (predict)** :
   - La fonction `predict()` calcule une sortie à partir des entrées en effectuant une somme pondérée des entrées et en appliquant la fonction sigmoïde.

3. **Rétropropagation (train)** :
   - La fonction `train()` ajuste les poids et le biais en fonction de l'erreur entre la sortie attendue et la sortie prédite. Cela se fait en calculant la dérivée de l'erreur par rapport aux poids et en appliquant la déscente de gradient pour mettre à jours les poids.

4. **Entraînement** :
   - Le perceptron est entraîné sur l'ensemble de données représentant la porte logique XOR. Le modèle est mis à jour pour minimiser l'erreur entre la sortie attendue et la sortie prédite pendant 10 000 étapes.

5. **Test** :
   - Après l'entraînement, le modèle est testé sur les 4 combinaisons possibles des entrées de la porte XOR (0, 0), (0, 1), (1, 0), (1, 1), et la sortie prédite est affichée.

### Fonctions principales

- `init_weights(double *w1, double *w2, double *bias)` : Initialise les poids et le biais avec des valeurs aléatoires.
- `predict(double input1, double input2, double w1, double w2, double bias)` : Effectue une prédiction à partir des entrées et des poids.
- `train(double input1, double input2, double target, double *w1, double *w2, double *bias, double learning_rate)` : Entraîne le perceptron en ajustant les poids à l'aide de la rétropropagation.

## Utilisation

1. Clonez le repo:
    ```bash
    git clone https://github.com/notpunchnox/Perceptron-C
    ```
2. Compilez le code :
   ```bash
   make
   ```
3. Exécutez le programme compilé:
    > Linux:
        ```bash
        ./bin/perceptron
        ```
    > Windows:
        ```bash
        ./bin/perceptron
        ```