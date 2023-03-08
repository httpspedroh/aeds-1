#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() 
{
    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    int var[2];

    printf("Digite o primeiro valor inteiro: ");
    scanf("%i", &var[0]);

    printf("Digite o segundo valor inteiro: ");
    scanf("%i", &var[1]);

    printf("\nConteúdo do maior endereço (%x): %i\n\n", &var[0] > &var[1] ? &var[0] : &var[1], &var[0] > &var[1] ? var[0] : var[1]);

    // --------------------------- //

    system("pause");

    return 0;
}