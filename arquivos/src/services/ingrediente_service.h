#ifndef INGREDIENTE_SERVICE_H
#define INGREDIENTE_SERVICE_H

#include "../models/ingrediente.h"

extern Ingrediente ingredientes[MAX_INGREDIENTES];
extern int num_ingredientes;

void adicionarIngrediente();
void listarIngredientes();
void editarIngrediente();
void removerIngrediente();

#endif