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

    int count = 0;

    for(int x = 0; x != strlen(string); x++) if(string[x] >= 97 && string[x] <= 122) count++;
    
    printf("\nO nome \"%s\" tem %i letras minúsculas.\n\n", string, count);

    // --------------------------- //

    system("pause");

    return 0;
}