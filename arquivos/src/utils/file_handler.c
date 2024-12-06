#include <stdio.h>
#include <string.h>
#include "file_handler.h"
#include "../services/pizza_service.h"
#include "../services/ingrediente_service.h"

#define ARQUIVO_PIZZAS "pizzas.dat"
#define ARQUIVO_INGREDIENTES "ingredientes.dat"

void exportarDados() {
    FILE* arquivoPizzas = fopen(ARQUIVO_PIZZAS, "wb");
    if (arquivoPizzas == NULL) {
        printf("Erro ao abrir arquivo de pizzas para exportacao.\n");
        return;
    }

    fwrite(&num_pizzas, sizeof(int), 1, arquivoPizzas);
    fwrite(cardapio, sizeof(Pizza), num_pizzas, arquivoPizzas);
    fclose(arquivoPizzas);

    FILE* arquivoIngredientes = fopen(ARQUIVO_INGREDIENTES, "wb");
    if (arquivoIngredientes == NULL) {
        printf("Erro ao abrir arquivo de ingredientes para exportacao.\n");
        return;
    }

    fwrite(&num_ingredientes, sizeof(int), 1, arquivoIngredientes);
    fwrite(ingredientes, sizeof(Ingrediente), num_ingredientes, arquivoIngredientes);
    fclose(arquivoIngredientes);

    printf("Dados exportados com sucesso!\n");
}

void importarDados() {
    FILE* arquivoPizzas = fopen(ARQUIVO_PIZZAS, "rb");
    if (arquivoPizzas != NULL) {
        fread(&num_pizzas, sizeof(int), 1, arquivoPizzas);
        fread(cardapio, sizeof(Pizza), num_pizzas, arquivoPizzas);
        fclose(arquivoPizzas);
    }

    FILE* arquivoIngredientes = fopen(ARQUIVO_INGREDIENTES, "rb");
    if (arquivoIngredientes != NULL) {
        fread(&num_ingredientes, sizeof(int), 1, arquivoIngredientes);
        fread(ingredientes, sizeof(Ingrediente), num_ingredientes, arquivoIngredientes);
        fclose(arquivoIngredientes);
    }

    printf("Dados importados com sucesso!\n");
}
