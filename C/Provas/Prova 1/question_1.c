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

    // Exerc�cio 1
    int lim_inf = 0, lim_sup = 0, somatorio = 0;

    do
    {
        printf("1. Insira os limites inteiros inferior e superior, separados por espa�o: ");
        scanf("%i %i", &lim_inf, &lim_sup);
    } 
    while(lim_inf <= 0 || lim_sup <= 0);
    
    printf("1.R: N�meros pares no intervalo: ");

    for(int x = lim_inf + 1; x < lim_sup; x++)
    {
        if(x % 2 == 0) 
        {
            printf("%i ", x);
            somatorio += x;
        }
    }

    printf("\n1.R: Somat�rio = %i\n\n", somatorio);
    
    // ----------------------- //

	system("pause");
    return 0;
}