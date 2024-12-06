#include <stdio.h>
#include <string.h>
#include "ingrediente.h"

// Inicializa o n�mero de ingredientes dispon�veis
int num_ingredientes = 0;
Ingrediente ingredientes[MAX_INGREDIENTES]; // Corre��o: Adicionando o fechamento do array

// Fun��o para adicionar um novo ingrediente
void adicionarIngrediente() {
    if (num_ingredientes >= MAX_INGREDIENTES) {
        printf("Capacidade m�xima de ingredientes atingida.\n");
        return;
    }

    Ingrediente novoIngrediente;
    printf("Digite o nome do ingrediente: ");
    getchar();  // Limpa o buffer
    fgets(novoIngrediente.nome, sizeof(novoIngrediente.nome), stdin);
    novoIngrediente.nome[strcspn(novoIngrediente.nome, "\n")] = 0; // Remove o '\n'

    printf("Digite o pre�o do ingrediente: ");
    scanf("%f", &novoIngrediente.preco);

    // Atribui um ID baseado na posi��o atual + 1 (para come�ar em 1)
    novoIngrediente.id = num_ingredientes + 1;
    ingredientes[num_ingredientes++] = novoIngrediente; // Adiciona o novo ingrediente
    printf("Ingrediente adicionado com sucesso! ID: %d\n", novoIngrediente.id);
}

// Fun��o para listar todos os ingredientes
void listarIngredientes() {
    if (num_ingredientes == 0) {
        printf("N�o h� ingredientes cadastrados.\n");
        return;
    }

    for (int i = 0; i < num_ingredientes; i++) {
        printf("ID: %d | Nome: %s | Pre�o: %.2f\n",
               ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }
}

// Fun��o para editar um ingrediente
void editarIngrediente() {
    int id;
    printf("Digite o ID do ingrediente que deseja editar: ");
    scanf("%d", &id);

    // Verifica se o ID est� dentro do intervalo v�lido
    if (id < 1 || id > num_ingredientes) {
        printf("Ingrediente n�o encontrado.\n");
        return;
    }

    // Ajusta o �ndice para o array (ID - 1)
    Ingrediente* ingrediente = &ingredientes[id - 1];

    printf("Digite o novo nome do ingrediente: ");
    getchar();  // Limpa o buffer
    fgets(ingrediente->nome, sizeof(ingrediente->nome), stdin);
    ingrediente->nome[strcspn(ingrediente->nome, "\n")] = 0; // Remove o '\n'

    printf("Digite o novo pre�o do ingrediente: ");
    scanf("%f", &ingrediente->preco);

    printf("Ingrediente atualizado com sucesso!\n");
}

// Fun��o para remover um ingrediente
void removerIngrediente() {
    int id;
    printf("Digite o ID do ingrediente que deseja remover: ");
    scanf("%d", &id);

    // Verifica se o ID est� dentro do intervalo v�lido
    if (id < 1 || id > num_ingredientes) {
         printf("Ingrediente n�o encontrado.\n");
        return;
    }

    // Ajusta o �ndice para o array (ID - 1)
    for (int i = id - 1; i < num_ingredientes - 1; i++) {
        ingredientes[i] = ingredientes[i + 1];
    }

    num_ingredientes--;
    printf("Ingrediente removido com sucesso!\n");
}

// Fun��o para exportar os ingredientes
void exportarIngredientes() {
    FILE *arquivo = fopen("ingredientes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para exporta��o.\n");
        return;
    }

    // Exportar ingredientes
    for (int i = 0; i < num_ingredientes; i++) {
        fprintf(arquivo, "ID: %d | Nome: %s | Pre�o: %.2f\n",
                ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }

    fclose(arquivo);
    printf("Ingredientes exportados com sucesso!\n");
}

// Fun��o para importar os ingredientes
void importarIngredientes() {
    FILE *arquivo = fopen("ingredientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para importa��o.\n");
        return;
    }

    while (fscanf(arquivo, "ID: %d | Nome: %49[^\n] | Pre�o: %f\n",
                  &ingredientes[num_ingredientes].id, ingredientes[num_ingredientes].nome,
                  &ingredientes[num_ingredientes].preco) == 3) {
        // Verifica se n�o ultrapassou o limite de ingredientes
        if (num_ingredientes >= MAX_INGREDIENTES) {
            printf("Capacidade m�xima de ingredientes atingida durante a importa��o.\n");
            break;
        }
        num_ingredientes++;
    }

    fclose(arquivo);
    printf("Ingredientes importados com sucesso!\n");
}
