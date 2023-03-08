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

    char string[25];

    printf("> Digite um nome: ");
    scanf("%[^\n]s", &string);

    printf("\n4 primeiras letras do nome: ");

    for(int x = 0; x != 4; x++) printf("%c", string[x]);
    
    printf("\n\n");

    // --------------------------- //

    system("pause");

    return 0;
}