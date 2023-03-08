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

    int vecint[5];

    for(int x = 0; x != 5; x++)
    {
        printf("Digite o valor %i: ", x + 1);
        scanf("%i", vecint + x);

        dobra(vecint + x);
    }

    printf("\n");

    for(int x = 0; x != 5; x++) printf("vecint[%i] = %i\n", x, *(vecint + x));

    printf("\n");

    // --------------------------- //

    system("pause");

    return 0;
}