#ifndef INGREDIENTE_H
#define INGREDIENTE_H

typedef struct {
    int id;
    char nome[50];
    float preco;
} Ingrediente;

void adicionarIngrediente(Ingrediente *ingredientes, int *contador);
void editarIngrediente(Ingrediente *ingredientes, int contador);
void removerIngrediente(Ingrediente *ingredientes, int *contador);
void listarIngredientes(Ingrediente *ingredientes, int contador);

#endif

