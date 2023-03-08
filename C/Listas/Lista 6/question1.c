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

    // Questão 1
    int values[10], q_pares = 0, q_impares = 0;

    for(int x = 0; x != 10; x++)
    {
        do
        {
            printf("> Digite o valor %i: ", x + 1);
            scanf("%i", &values[x]);
        } 
        while(values[x] < 0);

        if(values[x] % 2 == 0) q_pares++;
        else q_impares++;
    }

    printf("\n> Quantidade de pares: %i\n> Quantidade de ímpares: %i\n\n", q_pares, q_impares);

    // ----------------------- //

	system("pause");
    return 0;
}