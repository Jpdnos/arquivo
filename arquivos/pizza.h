#ifndef PIZZA_H
#define PIZZA_H

#include "ingrediente.h"  // O MAX_INGREDIENTES será acessado aqui

#define MAX_PIZZAS 100

typedef struct {
    int id;  // Chave da pizza
    char nome[50];  // Nome da pizza
    char tamanho;  // Tamanho da pizza (P, M, G)
    float preco;  // Valor base da pizza
    Ingrediente ingredientes[MAX_INGREDIENTES];  // Array com os ingredientes
    int numIngredientes;  // Contador de ingredientes
} Pizza;

extern Pizza cardapio[MAX_PIZZAS];
extern int num_pizzas;

void adicionarPizza();
void listarPizzas();
void editarPizza();
void removerPizza();
void exportarPizzas();
void importarPizzas();

#endif

