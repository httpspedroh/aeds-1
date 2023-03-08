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

    // Questão 6
    int values[20];

    for(int x = 0; x != 20; x++)
    {
        printf("> Insira o valor do vetor values[%i]: ", x);
        scanf("%i", &values[x]);
    }

    printf("\n");

    for(int x = 0; x != 10; x++)
    {
        int anterior = values[x];

        values[x] = values[19 - x];
        values[19 - x] = anterior;
    }

    for(int x = 0; x != 20; x++) printf("values[%i] = %i\n", x, values[x]);
    
    printf("\n");

    // ----------------------- //

	system("pause");
    return 0;
}