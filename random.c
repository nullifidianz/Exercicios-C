#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numeroAleatorio, chute, tentativas;
    char jogarNovamente;

    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    do
    {                                       // Loop de jogo
        numeroAleatorio = rand() % 100 + 1; // Gera um novo número aleatório
        tentativas = 0;

        printf("Advinhe um numero de 1 a 100:\n");

        do
        {
            printf("Digite seu chute: ");
            scanf("%d", &chute);
            tentativas++;

            if (chute > numeroAleatorio)
            {
                printf("Muito alto!\n");
            }
            else if (chute < numeroAleatorio)
            {
                printf("Muito baixo!\n");
            }
        } while (chute != numeroAleatorio); // Continua até o acerto

        printf("Voce acertou em %d tentativas!\n", tentativas);

        printf("Jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente);

    } while (jogarNovamente == 's');

    return 0;
}
