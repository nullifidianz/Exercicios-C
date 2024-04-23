#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINHAS 100
#define MAX_COMPRIMENTO_LINHA 100

char texto[MAX_LINHAS][MAX_COMPRIMENTO_LINHA];
int numLinhas = 0;

void carregarArquivo(const char *nomeArquivo)
{
    FILE *fp = fopen(nomeArquivo, "r");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char linha[MAX_COMPRIMENTO_LINHA];
    while (fgets(linha, sizeof(linha), fp) != NULL)
    {
        strcpy(texto[numLinhas], linha);
        numLinhas++;
    }

    fclose(fp);
    printf("Arquivo carregado.\n");
}

void salvarArquivo(const char *nomeArquivo)
{
    FILE *fp = fopen(nomeArquivo, "w");
    if (fp == NULL)
    {
        printf("Erro ao salvar o arquivo!\n");
        return;
    }

    for (int i = 0; i < numLinhas; i++)
    {
        fputs(texto[i], fp);
    }

    fclose(fp);
    printf("Arquivo salvo.\n");
}

void mostrarTexto()
{
    if (numLinhas == 0)
    {
        printf("Nenhum texto para mostrar.\n");
        return;
    }

    for (int i = 0; i < numLinhas; i++)
    {
        printf("%d: %s", i + 1, texto[i]);
    }
}

void editarTexto()
{
    mostrarTexto();

    int numLinha;
    printf("Entre com o número da linha a editar (ou 0 para cancelar): ");
    scanf("%d", &numLinha);

    if (numLinha >= 1 && numLinha <= numLinhas)
    {
        printf("Entre com o novo texto: ");
        scanf(" ");
        fgets(texto[numLinha - 1], MAX_COMPRIMENTO_LINHA, stdin);
    }
    else if (numLinha != 0)
    {
        printf("Número de linha inválido.\n");
    }
}

int main()
{
    int escolha;

    while (1)
    {
        printf("\nEditor de Texto Simples\n");
        printf("1. Carregar Arquivo\n");
        printf("2. Salvar Arquivo\n");
        printf("3. Mostrar Texto\n");
        printf("4. Editar Texto\n");
        printf("5. Sair\n");
        printf("Entre com sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
        {
            char nomeArquivo[100];
            printf("Entre com o nome do arquivo: ");
            scanf("%s", nomeArquivo);
            carregarArquivo(nomeArquivo);
            break;
        }
        case 2:
        {
            char nomeArquivo[100];
            printf("Entre com o nome do arquivo: ");
            scanf("%s", nomeArquivo);
            salvarArquivo(nomeArquivo);
            break;
        }
        case 3:
            mostrarTexto();
            break;
        case 4:
            editarTexto();
            break;
        case 5:
            exit(0);
        default:
            printf("Escolha inválida!\n");
        }
    }

    return 0;
}
