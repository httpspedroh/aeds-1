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

    // Questão 5
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

    printf("\nTodos abaixo da diagonal: \n\n");

    for(int x = 0; x != 10; x++)
    {
        for(int y = 0; y != 10; y++)
        {
            if(x > y) printf("%i ", elements[x][y]);
            else printf("   ");
        }

        printf("\n");
    }

    printf("\n\n");

    // ----------------------- //

	system("pause");
    return 0;
}