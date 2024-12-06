#include <stdio.h>
#include "pizza.h"
#include "ingrediente.h"

void exibirMenu() {
    printf("Bem-vindo à Pizzaria\n");
    printf("1. Gerenciar Pizzas\n");
    printf("2. Gerenciar Ingredientes\n");
    printf("3. Exportar Dados\n");
    printf("4. Importar Dados\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        if (opcao == 1) {
            // Gerenciar Pizzas
            printf("1. Adicionar Pizza\n");
            printf("2. Listar Pizzas\n");
            printf("3. Editar Pizza\n");
            printf("4. Remover Pizza\n");
            printf("Escolha uma opção: ");
            int subOpcao;
            scanf("%d", &subOpcao);
            switch (subOpcao) {
                case 1: adicionarPizza(); break;
                case 2: listarPizzas(); break;
                case 3: editarPizza(); break;
                case 4: removerPizza(); break;
                default: printf("Opção inválida\n");
            }
        }
        else if (opcao == 2) {
            // Gerenciar Ingredientes
            printf("1. Adicionar Ingrediente\n");
            printf("2. Listar Ingredientes\n");
            printf("3. Editar Ingrediente\n");
            printf("4. Remover Ingrediente\n");
            printf("Escolha uma opção: ");
            int subOpcao;
            scanf("%d", &subOpcao);
            switch (subOpcao) {
                case 1: adicionarIngrediente(); break;
                case 2: listarIngredientes(); break;
                case 3: editarIngrediente(); break;
                case 4: removerIngrediente(); break;
                default: printf("Opção inválida\n");
            }
        }
        else if (opcao == 3) {
            // Exportar Dados
            exportarPizzas();
            exportarIngredientes();
        }
        else if (opcao == 4) {
            // Importar Dados
            importarPizzas();
            importarIngredientes();
        }
        else if (opcao == 5) {
            printf("Saindo do sistema...\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
