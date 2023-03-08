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

// -------------------------------------------------------------- //

int main() 
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    // ----------------------- //

    // Questão 14
    int matriz[3][3], matrizInv[3][3];

    printf("> Matriz original:\n\n");

    for(int x = 0; x != 3; x++)
    {
        for(int y = 0; y != 3; y++) 
        {
            matriz[x][y] = random(10);

            printf("%i ", matriz[x][y]);
        }

        printf("\n");
    }

    printf("\n> Matriz alterada:\n\n");

    for(int x = 0; x != 3; x++)
    {
        for(int y = 0; y != 3; y++) 
        {
            matrizInv[x][y] = matriz[y][x];

            printf("%i ", matrizInv[x][y]);
        }

        printf("\n");
    }

    printf("\n");

    // ----------------------- //

	system("pause");
    return 0;
}