#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>

// -------------------------------------------------------------- //

int main() 
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------------- //

    // Questão 4
    float vetor1[10], vetor2[10], vetor3[10];

    for(int x = 0; x != 10; x++)
    {
        printf("> Insira o valor de vetor1[%i] e vetor2[%i], separados por espaço: ", x, x);
        scanf("%f %f", &vetor1[x], &vetor2[x]);

        vetor3[x] = vetor1[x] * vetor2[x];
    }

    printf("> Resultado: \n\n");

    for(int x = 0; x != 10; x++)
    {
        printf("vetor3[%i] = %.2f\n", x, vetor3[x]);
    }

    printf("\n\n");
    
    // ----------------------- //

	system("pause");
    return 0;
}