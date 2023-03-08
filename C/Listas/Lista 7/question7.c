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

    // Questão 7
    int values[12];

    for(int x = 0; x != 12; x++)
    {
       values[x] = random(100);

       printf("values[%i] = %i\n", x, values[x]);
    }

    int valorX = 0, valorY = 0;

    do
    {
        printf("\n> Insira um valor X: (0 a 11) ");
        scanf("%i", &valorX);
    } 
    while(valorX < 0 || valorX > 11);
    
    do
    {
        printf("> Insira um valor Y: (0 a 11) ");
        scanf("%i", &valorY);
    } 
    while(valorY < 0 || valorY > 11);

    printf("\nSoma de values[%i] e values[%i] = %i\n\n", valorX, valorY, values[valorX] + values[valorY]);

    // ----------------------- //

	system("pause");
    return 0;
}