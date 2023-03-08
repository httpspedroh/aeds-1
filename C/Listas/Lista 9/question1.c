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

    int inter = 9; 
    int *i = &inter;

    float flut = 5.5; 
    float *f = &flut;

    char carac = 'c'; 
    char *c = &carac;

    printf("Antes:\n\ni = %i\nf = %.2f\nc = %c\n\n", inter, flut, carac);

    *i = 15;
    *f = 9.99;
    *c = 'z';

    printf("Depois:\n\ni = %i\nf = %.2f\nc = %c\n\n", inter, flut, carac);

    // --------------------------- //

    system("pause");

    return 0;
}