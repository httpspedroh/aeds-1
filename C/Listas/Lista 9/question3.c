#include <stdio.h>
#include <locale.h>
#include <conio.h>

// ---------------------------------------------------------------------------------------------------------------------- //

void invertContent(int *a, int *b)
{
    int old = *a;

    *a = *b;
    *b = old;
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

    printf("\nAntes:\n\nA = %i, B = %i\n", var[0], var[1]);

    invertContent(&var[0], &var[1]);

    printf("\nDepois:\n\nA = %i, B = %i\n\n", var[0], var[1]);
    
    // --------------------------- //

    system("pause");

    return 0;
}