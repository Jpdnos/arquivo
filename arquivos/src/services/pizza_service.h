#ifndef PIZZA_SERVICE_H
#define PIZZA_SERVICE_H

#include "../models/pizza.h"

extern Pizza cardapio[MAX_PIZZAS];
extern int num_pizzas;

void adicionarPizza();
void listarPizzas();
void editarPizza();
void removerPizza();
void venderPizza();
void gerenciarIngredientesPizza(Pizza* pizza);
Ingrediente* buscarIngrediente(int id);

#endif