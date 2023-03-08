#include <stdio.h>
#include <locale.h>
#include <conio.h>

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
    }

    printf("\n");

    for(int x = 0; x != 5; x++) 
    {
        if(*(vecint + x) % 2 == 0) printf("vecint[%i] = %i (%x)\n", x, *(vecint + x), vecint + x);
    }

    printf("\n");

    // --------------------------- //

    system("pause");

    return 0;
}