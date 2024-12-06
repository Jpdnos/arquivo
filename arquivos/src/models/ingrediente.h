#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#define MAX_INGREDIENTES 20

typedef struct {
    int id;
    char nome[50];
    float preco;
} Ingrediente;

#endif