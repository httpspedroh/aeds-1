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

    // Questão 9
    int vector[16];

    for(int x = 0; x != 16; x++) 
    {
        vector[x] = minrand(10, 100);

        printf("vector[%i] = %i\n", x, vector[x]);
    }

    for(int x = 0; x != 8; x++)
    {
        int antigo = vector[x + 8];

        vector[x + 8] = vector[x];
        vector[x] = antigo;
    }

    printf("\nAlterando:\n\n");

    for(int x = 0; x != 16; x++) printf("vector[%i] = %i\n", x, vector[x]);

    printf("\n\n");

    // ----------------------- //

	system("pause");
    return 0;
}