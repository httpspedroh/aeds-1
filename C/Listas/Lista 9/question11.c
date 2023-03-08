#include <stdio.h>
#include <locale.h>
#include <conio.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int ordenar(int *a, int *b, int *c)
{
    if(*a == *b && *b == *c && *a == *c) return 1;
    else 
    {
        int old;

        if(*a > *b)
        {
            old = *a;
            
            *a = *b;
            *b = old;
        }

        if(*b > *c) 
        {
            old = *b;
            
            *b = *c;
            *c = old;
        }

        if(*a > *b)
        {
            old = *a;
            
            *a = *b;
            *b = old;
        }
        return 0;
    }
}

// ---------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    int vecint[3];

    for(int x = 0; x != 3; x++)
    {
        printf("Digite o valor %i: ", x + 1);
        scanf("%i", vecint + x);
    }

    printf("\nAntes:\n\nA = %i, B = %i, C = %i\n", *vecint, *(vecint + 1), *(vecint + 2));

    printf("\nAs variáveis %s iguais.\n", ordenar(vecint, vecint + 1, vecint + 2) ? "são" : "não são");

    printf("\nDepois:\n\nA = %i, B = %i, C = %i\n\n", *vecint, *(vecint + 1), *(vecint + 2));

    // --------------------------- //

    system("pause");

    return 0;
}