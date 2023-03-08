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

    // Questão 13
    int vectorPar[20], vectorImpar[20], vectorFinal[20];

    printf("> Vetor par:\n\n");

    for(int x = 0; x != 20; x++) 
    {
        vectorPar[x] = random(300);

        printf("vectorPar[%i] = %i\n", x, vectorPar[x]);
    }
    
    printf("\n> Vetor ímpar:\n\n");

    for(int x = 0; x != 20; x++) 
    {
        vectorImpar[x] = random(300);

        printf("vectorImpar[%i] = %i\n", x, vectorImpar[x]);
    }

    printf("\n> Vetor final:\n\n");

    for(int x = 0; x != 20; x++)
    {
        vectorFinal[x] = x % 2 == 0 ? vectorPar[x] : vectorImpar[x];
        
        printf("vectorFinal[%i] = %i\n", x, vectorFinal[x]);
    }

    printf("\n\n");

    // ----------------------- //

	system("pause");
    return 0;
}