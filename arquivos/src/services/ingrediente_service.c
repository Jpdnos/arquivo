#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ingrediente_service.h"
#include "pizza_service.h"

Ingrediente ingredientes[MAX_INGREDIENTES];
int num_ingredientes = 0;

void adicionarIngrediente() {
    if (num_ingredientes >= MAX_INGREDIENTES) {
        printf("Capacidade maxima de ingredientes atingida.\n");
        return;
    }

    Ingrediente novoIngrediente;
    novoIngrediente.id = num_ingredientes + 1;  

    printf("Digite o nome do ingrediente: ");
    getchar();
    fgets(novoIngrediente.nome, sizeof(novoIngrediente.nome), stdin);
    novoIngrediente.nome[strcspn(novoIngrediente.nome, "\n")] = 0;

    printf("Digite o preco do ingrediente: ");
    scanf("%f", &novoIngrediente.preco);

    ingredientes[num_ingredientes++] = novoIngrediente;
    printf("Ingrediente cadastrado com sucesso!\n");
}

void listarIngredientes() {
    if (num_ingredientes == 0) {
        printf("Nenhum ingrediente cadastrado.\n");
        return;
    }

    printf("\n=== Lista de Ingredientes ===\n");
    for (int i = 0; i < num_ingredientes; i++) {
        printf("ID: %d\n", ingredientes[i].id);
        printf("Nome: %s\n", ingredientes[i].nome);
        printf("Preco: R$ %.2f\n", ingredientes[i].preco);
        printf("------------------------\n");
    }
}

void editarIngrediente() {
    if (num_ingredientes == 0) {
        printf("Nenhum ingrediente cadastrado.\n");
        return;
    }

    listarIngredientes();
    int id;
    printf("\nDigite o ID do ingrediente que deseja editar: ");
    scanf("%d", &id);

    Ingrediente* ingrediente = NULL;
    for (int i = 0; i < num_ingredientes; i++) {
        if (ingredientes[i].id == id) {
            ingrediente = &ingredientes[i];
            break;
        }
    }

    if (ingrediente == NULL) {
        printf("Ingrediente nao encontrado.\n");
        return;
    }

    int opcao;
    do {
        printf("\n=== Editar Ingrediente ===\n");
        printf("1. Nome\n");
        printf("2. Preco\n");
        printf("3. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Novo nome: ");
                getchar();
                fgets(ingrediente->nome, sizeof(ingrediente->nome), stdin);
                ingrediente->nome[strcspn(ingrediente->nome, "\n")] = 0;
                printf("Nome atualizado com sucesso!\n");
                break;
            case 2:
                printf("Novo preco: ");
                scanf("%f", &ingrediente->preco);
                printf("Preco atualizado com sucesso!\n");
                break;
            case 3:
                printf("Voltando ao menu anterior...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);
}

void removerIngrediente() {
    if (num_ingredientes == 0) {
        printf("Nenhum ingrediente cadastrado.\n");
        return;
    }

    listarIngredientes();
    int id;
    printf("\nDigite o ID do ingrediente que deseja remover: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < num_ingredientes; i++) {
        if (ingredientes[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Ingrediente nao encontrado.\n");
        return;
    }

    
    for (int i = 0; i < num_pizzas; i++) {
        for (int j = 0; j < cardapio[i].numIngredientes; j++) {
            if (cardapio[i].ingredientes[j].id == id) {
                printf("Este ingrediente nao pode ser removido pois esta sendo usado na pizza '%s'.\n",
                       cardapio[i].nome);
                return;
            }
        }
    }

    for (int i = index; i < num_ingredientes - 1; i++) {
        ingredientes[i] = ingredientes[i + 1];
    }
    num_ingredientes--;
    printf("Ingrediente removido com sucesso!\n");
}
