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

    char string[100];

    printf("> Digite uma palavra/frase: ");
    scanf("%[^\n]s", &string);

    printf("> String digitada: %s\n\n", string);

    // --------------------------- //

    system("pause");

    return 0;
}