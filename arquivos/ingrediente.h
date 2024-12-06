#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#define MAX_INGREDIENTES 10

typedef struct {
    int id;
    char nome[50];
    float preco;
} Ingrediente;

extern Ingrediente ingredientes[MAX_INGREDIENTES];
extern int num_ingredientes;

void adicionarIngrediente();
void listarIngredientes();
void editarIngrediente();
void removerIngrediente();
void exportarIngredientes(); // Declara��o da fun��o
void importarIngredientes(); // Declara��o da fun��o

#endif




