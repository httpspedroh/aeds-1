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

    // Questão 7
    int vectorX[10], vectorY[10], vectorUnion[20];

    for(int x = 0; x != 20; x++)
    {
        printf("> Insira o valor %i: ", x + 1);

        if(x < 10)
        {
            scanf("%i", &vectorX[x]);

            vectorUnion[x] = vectorX[x];
        }
        else
        {
            scanf("%i", &vectorY[x]);

            vectorUnion[x] = vectorY[x];
        }
    }

    for(int x = 0; x != 20; x++) printf("\nvectorUnion[%i] = %i", x, vectorUnion[x]);
    
    printf("\n\n");

    // ----------------------- //

	system("pause");
    return 0;
}