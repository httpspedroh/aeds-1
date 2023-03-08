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

    if(string[0] == 'a' || string[0] == 'A') printf("Nome digitado: %s\n\n", string);
    else printf("\n");
    
    // --------------------------- //

    system("pause");

    return 0;
}