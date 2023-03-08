#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char string[50], caractere;
    int posicao = -1;

    printf("> Digite a string: ");
    scanf(" %[^\n]s", &string);

    printf("> Digite o caractere: ");
    scanf(" %c", &caractere);

    do
    {
        printf("> Digite a posição: ");
        scanf("%i", &posicao);
    } 
    while(posicao < 0 || posicao > strlen(string));
    
    for(int x = posicao; x != strlen(string); x++)
    {
        if(string[x] == caractere) 
        {
            printf("\nO caractere \"%c\" foi encontrado na posição %i.\n\n", caractere, x);
            break;
        }
    }

    // --------------------------- //

    system("pause");

    return 0;
}