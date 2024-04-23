#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define DESCRICAO_TAREFA 100

struct Tarefa
{
    char descricao[DESCRICAO_TAREFA];
    int concluida;
};

void adicionarTarefa(struct Tarefa *tarefas, int *numTarefas);
void mostrarTarefas(struct Tarefa *tarefas, int numTarefas);
void marcarConcluida(struct Tarefa *tarefas, int numTarefas);
void excluirTarefa(struct Tarefa *tarefas, int *numTarefas);

int main()
{
    setlocale(LC_ALL, "pt-BR");
    struct Tarefa tarefas[100];
    int numTarefas = 0;
    int escolha;

    while (1)
    {
        printf("\nGerenciador de Tarefas\n");
        printf("1. Adicionar Tarefa\n");
        printf("2. Mostrar Tarefas\n");
        printf("3. Marcar como Concluída\n");
        printf("4. Excluir Tarefa\n");
        printf("5. Sair\n");
        printf("Entre com sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            adicionarTarefa(tarefas, &numTarefas);
            break;
        case 2:
            mostrarTarefas(tarefas, numTarefas);
            break;
        case 3:
            marcarConcluida(tarefas, numTarefas);
            break;
        case 4:
            excluirTarefa(tarefas, &numTarefas);
            break;
        case 5:
            exit(0);
        default:
            printf("Escolha inválida!\n");
        }
    }

    return 0;
}

// func que add tarefas
void adicionarTarefa(struct Tarefa *tarefas, int *numTarefas)
{
    printf("Entre com a descrição da tarefa: ");
    scanf(" %[^\n]", tarefas[*numTarefas].descricao);
    tarefas[*numTarefas].concluida = 0;
    (*numTarefas)++;
}

// func para visualizar tarefas
void mostrarTarefas(struct Tarefa *tarefas, int numTarefas)
{
    if (numTarefas == 0)
    {
        printf("Sem tarefas para mostrar.\n");
    }
    else
    {
        printf("Tarefas:\n");
        for (int i = 0; i < numTarefas; i++)
        {
            printf("%d. %s (%s)\n", i + 1, tarefas[i].descricao, tarefas[i].concluida ? "Concluída" : "Pendente");
        }
    }
}

// marca tarefas como concluídas
void marcarConcluida(struct Tarefa *tarefas, int numTarefas)
{
    int numTarefa;
    printf("Entre com o número da tarefa: ");
    scanf("%d", &numTarefa);
    if (numTarefa >= 1 && numTarefa <= numTarefas)
    {
        tarefas[numTarefa - 1].concluida = 1;
        printf("Tarefa marcada como concluída.\n");
    }
    else
    {
        printf("Número de tarefa inválido.\n");
    }
}

void excluirTarefa(struct Tarefa *tarefas, int *numTarefas)
{
    int numTarefa;
    printf("Entre com o número da tarefa: ");
    scanf("%d", &numTarefa);
    if (numTarefa >= 1 && numTarefa <= *numTarefas)
    {
        for (int i = numTarefa - 1; i < *numTarefas - 1; i++)
        {
            tarefas[i] = tarefas[i + 1];
        }
        (*numTarefas)--;
        printf("Tarefa excluída.\n");
    }
    else
    {
        printf("Número de tarefa inválido.\n");
    }
}
