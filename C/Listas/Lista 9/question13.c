#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

// ---------------------------------------------------------------------------------------------------------------------- //

void percorreArray(int *array)
{
    for(int x = 0; x != 20; x++)
    {
        printf("array[%i] = %i (%x)\n", x, *(array + x), array + x);
    }

    printf("\n");
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

    int array[20];

    for(int x = 0; x != 20; x++) *(array + x) = minrand(0, 100);

    percorreArray(array);

    // --------------------------- //

    system("pause");

    return 0;
}