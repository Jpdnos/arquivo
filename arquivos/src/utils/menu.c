#include <stdio.h>
#include "menu.h"
#include "../services/pizza_service.h"
#include "../services/ingrediente_service.h"

void exibirMenuPrincipal() {
    printf("\n=== Sistema de Gerenciamento de Pizzaria ===\n");
    printf("1. Gerenciar Pizzas\n");
    printf("2. Gerenciar Ingredientes\n");
    printf("3. Exportar Dados\n");
    printf("4. Importar Dados\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

void exibirMenuPizzas() {
    int opcao;
    do {
        printf("\n=== Gerenciamento de Pizzas ===\n");
        printf("1. Adicionar Pizza\n");
        printf("2. Listar Pizzas\n");
        printf("3. Editar Pizza\n");
        printf("4. Remover Pizza\n");
        printf("5. Vender Pizza\n");
        printf("6. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarPizza();
                break;
            case 2:
                listarPizzas();
                break;
            case 3:
                editarPizza();
                break;
            case 4:
                removerPizza();
                break;
            case 5:
               venderPizza();
                break;
            case 6:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 6);
}

void exibirMenuIngredientes() {
    int opcao;
    do {
        printf("\n=== Gerenciamento de Ingredientes ===\n");
        printf("1. Adicionar Ingrediente\n");
        printf("2. Listar Ingredientes\n");
        printf("3. Editar Ingrediente\n");
        printf("4. Remover Ingrediente\n");
        printf("5. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarIngrediente();
                break;
            case 2:
                listarIngredientes();
                break;
            case 3:
                editarIngrediente();
                break;
            case 4:
                removerIngrediente();
                break;
            case 5:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);
}
