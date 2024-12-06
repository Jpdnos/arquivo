#include <stdio.h>
#include "../src/utils/menu.h" 
#include "../src/services/pizza_service.h"
#include "../src/services/ingrediente_service.h"
#include "../src/utils/file_handler.h"

int main() {
    int opcao;

    do {
        exibirMenuPrincipal();

       
        if (scanf("%d", &opcao) != 1) {
            limparBuffer(); 
            printf("Entrada invalida. Por favor, insira um numero valido.\n");
            continue; 
        }

        switch (opcao) {
            case 1:
                exibirMenuPizzas();
                break;
            case 2:
                exibirMenuIngredientes();
                break;
            case 3:
                exportarDados();
                break;
            case 4:
                importarDados();
                break;
            case 5:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}


