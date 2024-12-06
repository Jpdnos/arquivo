#include <stdio.h>
#include <string.h>
#include "ingrediente.h"

// Inicializa o número de ingredientes disponíveis
int num_ingredientes = 0;
Ingrediente ingredientes[MAX_INGREDIENTES]; // Correção: Adicionando o fechamento do array

// Função para adicionar um novo ingrediente
void adicionarIngrediente() {
    if (num_ingredientes >= MAX_INGREDIENTES) {
        printf("Capacidade máxima de ingredientes atingida.\n");
        return;
    }

    Ingrediente novoIngrediente;
    printf("Digite o nome do ingrediente: ");
    getchar();  // Limpa o buffer
    fgets(novoIngrediente.nome, sizeof(novoIngrediente.nome), stdin);
    novoIngrediente.nome[strcspn(novoIngrediente.nome, "\n")] = 0; // Remove o '\n'

    printf("Digite o preço do ingrediente: ");
    scanf("%f", &novoIngrediente.preco);

    // Atribui um ID baseado na posição atual + 1 (para começar em 1)
    novoIngrediente.id = num_ingredientes + 1;
    ingredientes[num_ingredientes++] = novoIngrediente; // Adiciona o novo ingrediente
    printf("Ingrediente adicionado com sucesso! ID: %d\n", novoIngrediente.id);
}

// Função para listar todos os ingredientes
void listarIngredientes() {
    if (num_ingredientes == 0) {
        printf("Não há ingredientes cadastrados.\n");
        return;
    }

    for (int i = 0; i < num_ingredientes; i++) {
        printf("ID: %d | Nome: %s | Preço: %.2f\n",
               ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }
}

// Função para editar um ingrediente
void editarIngrediente() {
    int id;
    printf("Digite o ID do ingrediente que deseja editar: ");
    scanf("%d", &id);

    // Verifica se o ID está dentro do intervalo válido
    if (id < 1 || id > num_ingredientes) {
        printf("Ingrediente não encontrado.\n");
        return;
    }

    // Ajusta o índice para o array (ID - 1)
    Ingrediente* ingrediente = &ingredientes[id - 1];

    printf("Digite o novo nome do ingrediente: ");
    getchar();  // Limpa o buffer
    fgets(ingrediente->nome, sizeof(ingrediente->nome), stdin);
    ingrediente->nome[strcspn(ingrediente->nome, "\n")] = 0; // Remove o '\n'

    printf("Digite o novo preço do ingrediente: ");
    scanf("%f", &ingrediente->preco);

    printf("Ingrediente atualizado com sucesso!\n");
}

// Função para remover um ingrediente
void removerIngrediente() {
    int id;
    printf("Digite o ID do ingrediente que deseja remover: ");
    scanf("%d", &id);

    // Verifica se o ID está dentro do intervalo válido
    if (id < 1 || id > num_ingredientes) {
         printf("Ingrediente não encontrado.\n");
        return;
    }

    // Ajusta o índice para o array (ID - 1)
    for (int i = id - 1; i < num_ingredientes - 1; i++) {
        ingredientes[i] = ingredientes[i + 1];
    }

    num_ingredientes--;
    printf("Ingrediente removido com sucesso!\n");
}

// Função para exportar os ingredientes
void exportarIngredientes() {
    FILE *arquivo = fopen("ingredientes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para exportação.\n");
        return;
    }

    // Exportar ingredientes
    for (int i = 0; i < num_ingredientes; i++) {
        fprintf(arquivo, "ID: %d | Nome: %s | Preço: %.2f\n",
                ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }

    fclose(arquivo);
    printf("Ingredientes exportados com sucesso!\n");
}

// Função para importar os ingredientes
void importarIngredientes() {
    FILE *arquivo = fopen("ingredientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para importação.\n");
        return;
    }

    while (fscanf(arquivo, "ID: %d | Nome: %49[^\n] | Preço: %f\n",
                  &ingredientes[num_ingredientes].id, ingredientes[num_ingredientes].nome,
                  &ingredientes[num_ingredientes].preco) == 3) {
        // Verifica se não ultrapassou o limite de ingredientes
        if (num_ingredientes >= MAX_INGREDIENTES) {
            printf("Capacidade máxima de ingredientes atingida durante a importação.\n");
            break;
        }
        num_ingredientes++;
    }

    fclose(arquivo);
    printf("Ingredientes importados com sucesso!\n");
}
