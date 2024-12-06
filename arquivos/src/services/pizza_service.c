#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ingrediente_service.h"
#include "pizza_service.h"
#include "../utils/file_handler.h"

Pizza cardapio[MAX_PIZZAS];
int num_pizzas = 0;



void adicionarPizza() {
    if (num_pizzas >= MAX_PIZZAS) {
        printf("Capacidade máxima de pizzas atingida.\n");
        return;
    }

    Pizza novaPizza;
    novaPizza.id = num_pizzas + 1;

    // Input do nome da pizza
    printf("Digite o nome da pizza: ");
    limparBuffer();  // Limpar o buffer antes de usar fgets
    fgets(novaPizza.nome, sizeof(novaPizza.nome), stdin);
    novaPizza.nome[strcspn(novaPizza.nome, "\n")] = '\0'; // Remove '\n'

    // Escolher tamanho da pizza
    do {
        printf("Digite o tamanho da pizza (P/M/G): ");
        scanf(" %c", &novaPizza.tamanho);
        novaPizza.tamanho = toupper(novaPizza.tamanho);
        if (novaPizza.tamanho != 'P' && novaPizza.tamanho != 'M' && novaPizza.tamanho != 'G') {
            printf("Tamanho inválido. Digite novamente (P/M/G).\n");
        }
    } while (novaPizza.tamanho != 'P' && novaPizza.tamanho != 'M' && novaPizza.tamanho != 'G');

    // Inserir preço base
    printf("Digite o preço base da pizza: ");
    while (scanf("%f", &novaPizza.preco) != 1) {
        limparBuffer();
        printf("Entrada inválida. Digite um número válido para o preço base: ");
    }

    novaPizza.numIngredientes = 0;
    char continuar;

    // Adicionar ingredientes à pizza
    do {
        if (novaPizza.numIngredientes >= MAX_INGREDIENTES) {
            printf("Limite máximo de ingredientes atingido.\n");
            break;
        }

        printf("\n=== Adicionar Ingrediente ===\n");
        listarIngredientes();

        int idIngrediente;
        printf("Digite o ID do ingrediente (0 para cancelar): ");
        while (scanf("%d", &idIngrediente) != 1) {
            limparBuffer();
            printf("Entrada inválida. Digite um número válido para o ID do ingrediente: ");
        }

        if (idIngrediente == 0) break;

       Ingrediente* buscarIngrediente(int id) {
    for (int i = 0; i < num_ingredientes; i++) {
        if (ingredientes[i].id == id) {
            return &ingredientes[i];  // Retorna o ingrediente encontrado
        }
    }
    return NULL;  // Retorna NULL se o ingrediente não for encontrado
}

        printf("Deseja adicionar mais ingredientes? (S/N): ");
        limparBuffer();
        scanf(" %c", &continuar);
        continuar = toupper(continuar);
    } while (continuar == 'S');

    cardapio[num_pizzas++] = novaPizza;
    printf("\nPizza '%s' cadastrada com sucesso!\n", novaPizza.nome);
}

void listarPizzas() {
    if (num_pizzas == 0) {
        printf("Nenhuma pizza cadastrada.\n");
        return;
    }

    printf("\n=== Cardápio de Pizzas ===\n");
    for (int i = 0; i < num_pizzas; i++) {
        printf("\nID: %d\n", cardapio[i].id);
        printf("Nome: %s\n", cardapio[i].nome);
        printf("Tamanho: %c\n", cardapio[i].tamanho);
        printf("Preço Base: R$ %.2f\n", cardapio[i].preco);
        printf("Ingredientes:\n");

        float precoTotal = cardapio[i].preco;
        for (int j = 0; j < cardapio[i].numIngredientes; j++) {
            printf("  - %s (R$ %.2f)\n",
                   cardapio[i].ingredientes[j].nome,
                   cardapio[i].ingredientes[j].preco);
            precoTotal += cardapio[i].ingredientes[j].preco;
        }
        printf("Preço Total: R$ %.2f\n", precoTotal);
        printf("------------------------\n");
    }
}

void editarPizza() {
    char adicionarMais;
    int id;
    printf("Digite o ID da pizza que deseja editar: ");
    scanf("%d", &id);

    if (id < 0 || id >= num_pizzas) {
        printf("Pizza não encontrada.\n");
        return;
    }

    Pizza* pizza = &cardapio[id];

    int subOpcao;  // Declare a variável aqui, antes do bloco de controle
    do {
        // Exibe o menu de opções para editar a pizza
        printf("\nEscolha o que deseja editar:\n");
        printf("1. Alterar o nome da pizza\n");
        printf("2. Alterar o tamanho da pizza\n");
        printf("3. Alterar o preço da pizza\n");
        printf("4. Adicionar ou remover ingredientes\n");
        printf("5. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &subOpcao);

        switch (subOpcao) {
            case 1:  // Alterar o nome da pizza
                printf("Digite o novo nome da pizza: ");
                getchar();  // Limpa o buffer
                fgets(pizza->nome, sizeof(pizza->nome), stdin);
                pizza->nome[strcspn(pizza->nome, "\n")] = 0;  // Remove o '\n'
                printf("Nome da pizza alterado com sucesso!\n");
                break;

            case 2:  // Alterar o tamanho da pizza
                printf("Digite o novo tamanho da pizza (P, M, G): ");
                scanf(" %c", &pizza->tamanho);
                // Valida o tamanho da pizza
                if (pizza->tamanho != 'P' && pizza->tamanho != 'M' && pizza->tamanho != 'G') {
                    printf("Tamanho inválido. Tente novamente.\n");
                } else {
                    printf("Tamanho da pizza alterado com sucesso!\n");
                }
                break;

            case 3:  // Alterar o preço da pizza
                printf("Digite o novo preço da pizza: ");
                scanf("%f", &pizza->preco);
                printf("Preço da pizza alterado com sucesso!\n");
                break;

            case 4:  // Adicionar ou remover ingredientes

                pizza->numIngredientes = 0; // Reinicia os ingredientes para reconfigurar a pizza
                do {
                    if (pizza->numIngredientes >= MAX_INGREDIENTES) {
                        printf("Número máximo de ingredientes atingido.\n");
                        break;
                    }

                    printf("Digite o nome do ingrediente que deseja adicionar: ");
                    getchar();  // Limpa o buffer
                    fgets(pizza->ingredientes[pizza->numIngredientes].nome, sizeof(pizza->ingredientes[pizza->numIngredientes].nome), stdin);
                    pizza->ingredientes[pizza->numIngredientes].nome[strcspn(pizza->ingredientes[pizza->numIngredientes].nome, "\n")] = 0;  // Remove o '\n'

                    printf("Digite o preço do ingrediente: ");
                    scanf("%f", &pizza->ingredientes[pizza->numIngredientes].preco);

                    pizza->numIngredientes++;
                    printf("Ingrediente adicionado com sucesso!\n");

                    printf("Deseja adicionar mais ingredientes? (s/n): ");
                    getchar(); 
                    scanf("%c", &adicionarMais);
                } while (adicionarMais == 's' || adicionarMais == 'S');
                break;

            case 5:  
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (subOpcao != 5);  
}


void removerPizza() {
    if (num_pizzas == 0) {
        printf("Nenhuma pizza cadastrada.\n");
        return;
    }

    listarPizzas();
    int id;
    printf("\nDigite o ID da pizza que deseja remover: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < num_pizzas; i++) {
        if (cardapio[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Pizza não encontrada.\n");
        return;
    }

    for (int i = index; i < num_pizzas - 1; i++) {
        cardapio[i] = cardapio[i + 1];
    }
    num_pizzas--;
    printf("Pizza removida com sucesso!\n");
}

void venderPizza() {
    if (num_pizzas == 0) {
        printf("Nenhuma pizza cadastrada.\n");
        return;
    }

    listarPizzas();
    int id;
    printf("\nDigite o ID da pizza que deseja vender: ");
    scanf("%d", &id);

    Pizza* pizza = NULL;
    for (int i = 0; i < num_pizzas; i++) {
        if (cardapio[i].id == id) {
            pizza = &cardapio[i];
            break;
        }
    }

    if (pizza == NULL) {
        printf("Pizza não encontrada.\n");
        return;
    }

    float precoTotal = pizza->preco;
    printf("\nPizza selecionada: %s\n", pizza->nome);
    printf("Preço base: R$ %.2f\n", pizza->preco);

    char adicionarExtra;
    do {
        printf("\nDeseja adicionar ingredientes extras? (S/N): ");
        scanf(" %c", &adicionarExtra);

        if (toupper(adicionarExtra) == 'S') {
            listarIngredientes();
            int idIngrediente;
            printf("Digite o ID do ingrediente extra (0 para cancelar): ");
            scanf("%d", &idIngrediente);

            if (idIngrediente == 0) break;

            Ingrediente* ing = buscarIngrediente(idIngrediente);
            if (ing != NULL) {
                precoTotal += ing->preco;
                printf("Ingrediente '%s' adicionado (+ R$ %.2f)\n",
                       ing->nome, ing->preco);
            } else {
                printf("Ingrediente não encontrado.\n");
            }
        }
    } while (toupper(adicionarExtra) == 'S');

    printf("\n=== Resumo da Venda ===\n");
    printf("Pizza: %s\n", pizza->nome);
    printf("Tamanho: %c\n", pizza->tamanho);
    printf("Preço Total: R$ %.2f\n", precoTotal);
    printf("\nVenda realizada com sucesso!\n");
}

void gerenciarIngredientesPizza(Pizza* pizza) {
    int opcao;
    do {
        printf("\n=== Gerenciar Ingredientes da Pizza ===\n");
        printf("1. Adicionar ingrediente\n");
        printf("2. Remover ingrediente\n");
        printf("3. Listar ingredientes atuais\n");
        printf("4. Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (pizza->numIngredientes >= MAX_INGREDIENTES) {
                    printf("Limite máximo de ingredientes atingido.\n");
                    break;
                }
                listarIngredientes();
                int idAdd;
                printf("Digite o ID do ingrediente para adicionar: ");
                scanf("%d", &idAdd);

                Ingrediente* ing = buscarIngrediente(idAdd);
                if (ing != NULL) {
                    pizza->ingredientes[pizza->numIngredientes] = *ing;
                    pizza->numIngredientes++;
                    printf("Ingrediente adicionado com sucesso!\n");
                } else {
                    printf("Ingrediente não encontrado.\n");
                }
                break;

            case 2:
                if (pizza->numIngredientes == 0) {
                    printf("Não há ingredientes para remover.\n");
                    break;
                }
                printf("\nIngredientes atuais:\n");
                for (int i = 0; i < pizza->numIngredientes; i++) {
                    printf("%d. %s\n", i + 1, pizza->ingredientes[i].nome);
                }
                int idxRemove;
                printf("Digite o número do ingrediente para remover (1-%d): ",
                       pizza->numIngredientes);
                scanf("%d", &idxRemove);
                idxRemove--; 

                if (idxRemove >= 0 && idxRemove < pizza->numIngredientes) {
                    for (int i = idxRemove; i < pizza->numIngredientes - 1; i++) {
                        pizza->ingredientes[i] = pizza->ingredientes[i + 1];
                    }
                    pizza->numIngredientes--;
                    printf("Ingrediente removido com sucesso!\n");
                } else {
                    printf("Índice inválido!\n");
                }
                break;

            case 3:
                if (pizza->numIngredientes == 0) {
                    printf("Esta pizza não possui ingredientes.\n");
                } else {
                    printf("\nIngredientes da pizza '%s':\n", pizza->nome);
                    for (int i = 0; i < pizza->numIngredientes; i++) {
                        printf("- %s (R$ %.2f)\n",
                               pizza->ingredientes[i].nome,
                               pizza->ingredientes[i].preco);
                    }
                }
                break;

            case 4:
                printf("Voltando ao menu anterior...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);
}

Ingrediente* buscarIngrediente(int id) {
    for (int i = 0; i < num_ingredientes; i++) {
        if (ingredientes[i].id == id) {
            return &ingredientes[i];
        }
    }
    return NULL;
}

