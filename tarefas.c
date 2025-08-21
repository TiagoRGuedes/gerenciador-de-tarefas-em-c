#include <stdio.h>
#include <string.h>

// Define a estrutura de uma tarefa
struct Tarefa {
    char titulo[100];
    char descricao[200];
    int concluida; // 0 para não concluída, 1 para concluída
};

// Função para adicionar uma nova tarefa
void adicionarTarefa(struct Tarefa tarefas[], int *totalTarefas) {
    if (*totalTarefas >= 50) {
        printf("Limite de tarefas atingido!\n");
        return;
    }

    struct Tarefa novaTarefa;
    printf("Digite o titulo da tarefa: ");
    scanf(" %[^\n]", novaTarefa.titulo); // Lê a linha inteira, incluindo espaços

    printf("Digite a descricao da tarefa: ");
    scanf(" %[^\n]", novaTarefa.descricao);

    novaTarefa.concluida = 0; // Por padrão, a tarefa não está concluída

    tarefas[*totalTarefas] = novaTarefa;
    (*totalTarefas)++;
    printf("Tarefa adicionada com sucesso!\n");
}

// Função para listar todas as tarefas
void listarTarefas(struct Tarefa tarefas[], int totalTarefas) {
    printf("\n--- LISTA DE TAREFAS ---\n");
    if (totalTarefas == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
    } else {
        for (int i = 0; i < totalTarefas; i++) {
            printf("Tarefa #%d:\n", i + 1);
            printf("  Titulo: %s\n", tarefas[i].titulo);
            printf("  Descricao: %s\n", tarefas[i].descricao);
            printf("  Status: %s\n", tarefas[i].concluida ? "Concluida" : "Pendente");
            printf("------------------------\n");
        }
    }
}

int main() {
    struct Tarefa minhasTarefas[50]; // Suporta até 50 tarefas
    int totalTarefas = 0;
    int opcao;

    do {
        printf("\nMenu de Gerenciamento de Tarefas:\n");
        printf("1. Adicionar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarTarefa(minhasTarefas, &totalTarefas);
                break;
            case 2:
                listarTarefas(minhasTarefas, totalTarefas);
                break;
            case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}