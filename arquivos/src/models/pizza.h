#ifndef PIZZA_H
#define PIZZA_H

#include "ingrediente.h"

#define MAX_PIZZAS 100

typedef struct {
    int id;
    char nome[50];
    char tamanho;
    float preco;
    Ingrediente ingredientes[MAX_INGREDIENTES];
    int numIngredientes;
} Pizza;

#endif