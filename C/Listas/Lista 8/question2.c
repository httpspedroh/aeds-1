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

    int count = 0;

	while(string[count] != '\0') count++;

    printf("> Tamanho: %i caracteres\n\n", count);

    // --------------------------- //

    system("pause");

    return 0;
}