#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

// ---------------------------------------------------------------------------------------------------------------------- //

void minEMax(int *vetor, int *min, int *max, int tam)
{
    int maior = 0, menor = 0;

    for(int x = 0; x != tam; x++)
    {
        if(*(vetor + x) < *(vetor + menor)) menor = x;
        if(*(vetor + x) > *(vetor + maior)) maior = x;
    }

    *min = *(vetor + menor);
    *max = *(vetor + maior);
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

    int array[tamanho];

    printf("\n");

    for(int x = 0; x != tamanho; x++) 
    {
        *(array + x) = minrand(0, 100);

        printf("array[%i] = %i\n", x, *(array + x));
    }

    int min, max;

    minEMax(array, &min, &max, tamanho);

    printf("\nValor mínimo = %i\nValor máximo = %i\n\n", min, max);

    // --------------------------- //

    system("pause");

    return 0;
}