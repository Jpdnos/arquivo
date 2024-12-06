#include <stdio.h>
#include <string.h>
#include "pizza.h"

// Inicializa o número de pizzas no cardápio
int num_pizzas = 0;
Pizza cardapio[MAX_PIZZAS];

// Função para adicionar uma nova pizza ao cardápio
void adicionarPizza() {
    if (num_pizzas >= MAX_PIZZAS) {
        printf("Capacidade máxima de pizzas atingida.\n");
        return;
    }

    Pizza novaPizza;
    printf("Digite o nome da pizza: ");
    getchar();  // Limpa o buffer
    fgets(novaPizza.nome, sizeof(novaPizza.nome), stdin);
    novaPizza.nome[strcspn(novaPizza.nome, "\n")] = 0; // Remove o '\n'

    printf("Digite o tamanho da pizza (P, M, G): ");
    scanf(" %c", &novaPizza.tamanho); // O espaço antes de %c ignora espaços em branco

    // Valida o tamanho da pizza
    if (novaPizza.tamanho != 'P' && novaPizza.tamanho != 'M' && novaPizza.tamanho != 'G') {
        printf("Tamanho inválido. Tente novamente.\n");
        return;
    }

    printf("Digite o preço da pizza: ");
    scanf("%f", &novaPizza.preco);

    // Adiciona ingredientes
    novaPizza.numIngredientes = 0; // Inicializa o contador de ingredientes
    char adicionarMais;
    do {
        if (novaPizza.numIngredientes >= MAX_INGREDIENTES) {
            printf("Número máximo de ingredientes atingido.\n");
            break;
        }

        printf("Digite o nome do ingrediente que deseja adicionar: ");
        getchar();  // Limpa o buffer
        fgets(novaPizza.ingredientes[novaPizza.numIngredientes].nome, sizeof(novaPizza.ingredientes[novaPizza.numIngredientes].nome), stdin);
        novaPizza.ingredientes[novaPizza.numIngredientes].nome[strcspn(novaPizza.ingredientes[novaPizza.numIngredientes].nome, "\n")] = 0; // Remove o '\n'

        printf("Digite o preço do ingrediente: ");
        scanf("%f", &novaPizza.ingredientes[novaPizza.numIngredientes].preco);

        novaPizza.numIngredientes++;
        printf("Ingrediente adicionado com sucesso!\n");

        printf("Deseja adicionar mais ingredientes? (s/n): ");
        getchar(); // Limpa o buffer
        scanf("%c", &adicionarMais);
    } while (adicionarMais == 's' || adicionarMais == 'S');

    novaPizza.id = num_pizzas; // Atribui um ID baseado na posição atual
    cardapio[num_pizzas++] = novaPizza; // Adiciona a nova pizza ao cardápio
    printf("Pizza adicionada com sucesso!\n");
}

// Função para listar todas as pizzas do cardápio
void listarPizzas() {
    if (num_pizzas == 0) {
        printf("Não há pizzas cadastradas.\n");
        return;
    }

    for (int i = 0; i < num_pizzas; i++) {
        printf("ID: %d | Nome: %s | Tamanho: %c | Preço: %.2f\n",
               cardapio[i].id, cardapio[i].nome, cardapio[i].tamanho, cardapio[i].preco);

        // Listar ingredientes da pizza
        printf("Ingredientes: ");
        for (int j = 0; j < cardapio[i].numIngredientes; j++) {
            printf("%s (%.2f) ", cardapio[i].ingredientes[j].nome, cardapio[i].ingredientes[j].preco);
        }
        printf("\n");
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
                    getchar(); // Limpa o buffer
                    scanf("%c", &adicionarMais);
                } while (adicionarMais == 's' || adicionarMais == 'S');
                break;

            case 5:  // Voltar ao menu principal
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (subOpcao != 5);  // O loop continua até o usuário escolher a opção 5
}



// Função para remover uma pizza do cardápio
void removerPizza() {
    int id;
    printf("Digite o ID da pizza que deseja remover: ");
    scanf("%d", &id);

    if (id < 0 || id >= num_pizzas) {
        printf("Pizza não encontrada.\n");
        return;
    }

    for (int i = id; i < num_pizzas - 1; i++) {
        cardapio[i] = cardapio[i + 1];
    }

    num_pizzas--;
    printf("Pizza removida com sucesso!\n");
}

// Função para exportar as pizzas
void exportarPizzas() {
    FILE *arquivo = fopen("cardapio_pizzas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para exportação.\n");
        return;
    }

    for (int i = 0; i < num_pizzas; i++) {
        fprintf(arquivo, "ID: %d | Nome: %s | Tamanho: %c | Preço: %.2f | Ingredientes: ",
                cardapio[i].id, cardapio[i].nome, cardapio[i].tamanho, cardapio[i].preco);

        for (int j = 0; j < cardapio[i].numIngredientes; j++) {
            fprintf(arquivo, "%s%s", cardapio[i].ingredientes[j].nome, (j < cardapio[i].numIngredientes - 1) ? ", " : "");
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Cardápio de pizzas exportado com sucesso!\n");
}

// Função para importar as pizzas
void importarPizzas() {
    FILE *arquivo = fopen("cardapio_pizzas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para importação.\n");
        return;
    }

    while (fscanf(arquivo, "ID: %d | Nome: %49[^\n] | Tamanho: %c | Preço: %f | Ingredientes: ",
                  &cardapio[num_pizzas].id, cardapio[num_pizzas].nome,
                  &cardapio[num_pizzas].tamanho, &cardapio[num_pizzas].preco) == 4) {

        // Inicializa o contador de ingredientes
        cardapio[num_pizzas].numIngredientes = 0;

        // Lê os ingredientes da linha
        char linha[256];
        fgets(linha, sizeof(linha), arquivo);
        char *token = strtok(linha, ",");

        while (token != NULL && cardapio[num_pizzas].numIngredientes < MAX_INGREDIENTES) {
            // Remove espaços em branco e nova linha do token
            token[strcspn(token, "\n")] = 0; // Remove o '\n'
            token[strcspn(token, " ")] = 0;  // Remove espaços

            // Aqui você deve buscar o ingrediente pelo nome ou ID, se necessário
            // Para simplicidade, vamos assumir que você tem uma função que busca pelo nome
            // Ingrediente ingredienteEncontrado = buscarIngredientePorNome(token);
            // cardapio[num_pizzas].ingredientes[cardapio[num_pizzas].numIngredientes++] = ingredienteEncontrado;

            // Para o exemplo, vamos apenas adicionar um ingrediente fictício
            strcpy(cardapio[num_pizzas].ingredientes[cardapio[num_pizzas].numIngredientes].nome, token);
            cardapio[num_pizzas].numIngredientes++;

            token = strtok(NULL, ",");
        }

        num_pizzas++;
    }

    fclose(arquivo);
    printf("Cardápio de pizzas importado com sucesso!\n");
}
