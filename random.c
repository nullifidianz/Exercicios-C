#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numeroAleatorio, chute, tentativas = 0;
    srand(time(NULL));
    numeroAleatorio = (rand() % 100 + 1); // gera de 1 a 100;

    printf("Escolha um numero de 1 a 100 e tente acertar o numero correto.\n");

    do
    {
        printf("chute: ");
        scanf("%d", &chute);
        tentativas++;

        if (chute > numeroAleatorio)
        {
            printf("chute muito alto.\n");
        }
        else if (chute < numeroAleatorio)
        {
            printf("chute muito baixo.\n");
        }
        else if (chute == numeroAleatorio)
        {
            printf("Voce acertou em %d tentativas, parabens!\n", tentativas);
            printf("Digite 0 para jogar novamente ou qualquer outra tecla para sair.");
        }
    } while (chute != 0);
    return 0;
}
