#include <stdio.h>
#include <locale.h>
#include <conio.h>

// ---------------------------------------------------------------------------------------------------------------------- //

void dobra(int *x)
{
    *x *= 2;
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

    dobra(&var[0]);
    dobra(&var[1]);

    printf("\n%i + %i = %i\n\n", var[0], var[1], var[0] + var[1]);
    
    // --------------------------- //

    system("pause");

    return 0;
}