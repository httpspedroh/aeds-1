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

    // Quest�o 10
    int vector[20];

    for(int x = 0; x != 20; x++) 
    {
        vector[x] = random(100);

        printf("vector[%i] = %i\n", x, vector[x]);
    }

    int search = 0, found = -1;

    printf("\n> Insira um n�mero para buscar no vetor: ");
    scanf("%i", &search);

    for(int x = 0; x != 20; x++)
    {
        if(vector[x] == search) 
        {
            found = x;
            break;
        }
    }

    if(found == -1) printf("> Valor n�o encontrado no vetor!\n\n");
    else printf("> Valor encontrado! Posi��o: %i\n\n", found);

    // ----------------------- //

	system("pause");
    return 0;
}