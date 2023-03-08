#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>

// -------------------------------------------------------------- //

// Exercício 3
int somaSerie(int i, int j, int k)
{
    int somatorio = 0;

    if(i == j) 
    {
        printf("%i ", j);
        return j;
    }
    else if(i > j) return somatorio;
    else 
    {
        printf("%i ", i);
        somatorio = i + somaSerie(i + k, j, k);
    }
    return somatorio;
}

// -------------------------------------------------------------- //

int main() 
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------------- //

    // Exercício 3
    int i = 0, j = 0, k = 0;

    do
    {
        printf("3. Insira os valores inteiros i, j, k, respectivamente, separados por espaço: ");
        scanf("%i %i %i", &i, &j, &k);
    } 
    while(j <= 0 || k <= 0);
    
    printf("\n3.R: Sequência: ");

    int somatorio = somaSerie(i, j, k);

    printf("\n3.R: Somatório = %i\n\n", somatorio);
    
    // ----------------------- //

	system("pause");
    return 0;
}