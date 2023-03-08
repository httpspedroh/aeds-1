#include <stdio.h>
#include <locale.h>
#include <conio.h>

// ---------------------------------------------------------------------------------------------------------------------- //

void soma(int *a, int *b)
{
    printf("\nA = %i, B = %i", *a, *b);
    printf("\nSoma = %i", *a += *b);
    printf("\nA = %i, B = %i\n\n", *a, *b);
}

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

    soma(&var[0], &var[1]);
    
    // --------------------------- //

    system("pause");

    return 0;
}