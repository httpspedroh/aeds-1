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

    // Questão 2
    int n_primeiros = 0;

    do
    {
        printf("> Digite a quantidade N de elementos desejados: (Mín. 1) ");
        scanf("%i", &n_primeiros);
    } 
    while(n_primeiros < 1);
    
    printf("> Sequência:");

    int elementos[n_primeiros];

    elementos[0] = 0;
    elementos[1] = 1;

    for(int x = 2; x < n_primeiros; x++) elementos[x] = elementos[x - 1] + elementos[x - 2];
    for(int x = 0; x != n_primeiros; x++) printf(" %i", elementos[x]);

    printf("\n\n");

    // ----------------------- //

	system("pause");
    return 0;
}