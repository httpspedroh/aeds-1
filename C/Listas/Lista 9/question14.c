#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int negativos(float *vet, int n)
{
    int count = 0;

    for(int x = 0; x != n; x++)
    {
        if(*(vet + x) < 0) count++;
    }
    return count;
}

int random(int interval)
{
	return rand() % interval;
}

int minrand(int min, int max)
{
	return random(max - min) + min;
}

// ---------------------------------------------------------------------------------------------------------------------- //

int main()
{
    srand(time(NULL));

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    int tamanho;

    printf("Digite o tamanho da array: ");
    scanf("%i", &tamanho);

    float array[tamanho];

    printf("\n");

    for(int x = 0; x != tamanho; x++) 
    {
        *(array + x) = minrand(-100, 100);

        printf("array[%i] = %.2f\n", x, *(array + x));
    }

    printf("\nHá %i números negativos na array criada.\n\n", negativos(&array, tamanho));

    // --------------------------- //

    system("pause");

    return 0;
}