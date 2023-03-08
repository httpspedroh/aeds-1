#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>

// -------------------------------------------------------------- //

int random(int interval)
{
	return rand() % interval;
}

int minrand(int min, int max)
{
	return random(max - min) + min;
}

// -------------------------------------------------------------- //

int main() 
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    // ----------------------- //

    // Questão 4
    int elements[10][10];

    for(int x = 0; x != 10; x++) // Linhas
    {
        for(int y = 0; y != 10; y++) // Colunas
        {
            elements[x][y] = minrand(10, 100);

            printf("%i ", elements[x][y]);
        }

        printf("\n");
    }

    printf("\nTodos acima da diagonal: \n\n");

    int soma = 0;

    for(int x = 0; x != 10; x++)
    {
        for(int y = 0; y != 10; y++)
        {
            if(y > x) 
            {
                printf("%i ", elements[x][y]);
                
                soma += elements[x][y];
            }
            else printf("   ");
        }

        printf("\n");
    }

    printf("\nSoma dos elementos acima da diagonal: %i\n\n", soma);

    // ----------------------- //

	system("pause");
    return 0;
}