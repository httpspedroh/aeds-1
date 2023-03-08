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

    // Questão 8
    int vector[10], atual = 0;

    for(int x = 0; x != 10; x++) vector[x] = -1;

    for(int x = 0; x != 10; x++)
    {
        for(int y = atual + 1; y != vector[x]; y++)
        {
            if(y % 2 != 0)
            {
                vector[x] = y;
                atual = y;
                break;
            }
        }

        printf("vector[%i] = %i\n", x, vector[x]);
    }

    printf("\n\n");

    // ----------------------- //

	system("pause");
    return 0;
}