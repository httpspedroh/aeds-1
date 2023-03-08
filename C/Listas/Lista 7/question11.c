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

    // Questão 11
    int vector[40], count = 0;

    for(int x = 0; x != 40; x++) 
    {
        vector[x] = random(500);

        if(vector[x] % 2 == 0) 
        {
            printf("vector[%i] = %i [É PAR]\n", x, vector[x]);
            count++;
        }
        else printf("vector[%i] = %i\n", x, vector[x]);
    }

    printf("\n> Contagem de números pares: %i\n\n", count);

    // ----------------------- //

	system("pause");
    return 0;
}