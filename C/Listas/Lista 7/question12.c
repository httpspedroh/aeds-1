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

    // Questão 12
    int vector[40], count = 0;

    for(int x = 0; x != 40; x++) 
    {
        vector[x] = minrand(-100, 100);

        printf("vector[%i] = %i\n", x, vector[x]);
    }

    printf("\n> Alterando:\n\n");

    for(int x = 0; x != 40; x++) 
    {
        if(vector[x] < 0) vector[x] = 0;

        printf("vector[%i] = %i\n", x, vector[x]);
    }

    // ----------------------- //

	system("pause");
    return 0;
}