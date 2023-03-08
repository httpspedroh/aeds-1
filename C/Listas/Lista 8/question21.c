#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char frase[2][50];

    printf("> Digite a frase 1: ");
    scanf(" %[^\n]s", &frase[0]);

    printf("> Digite a frase 2: ");
    scanf(" %[^\n]s", &frase[1]);

    for(int x = 0; x != strlen(frase[0]); x++) if(frase[0][x] == 65 || frase[0][x] == 97) frase[0][x] = 42;
    for(int x = 0; x != strlen(frase[1]); x++) if(frase[1][x] == 65 || frase[1][x] == 97) frase[1][x] = 42;
    
    printf("\nFrase 1: ");
    
    for(int x = strlen(frase[0]) - 1; x >= 0; x--) printf("%c", frase[0][x]);

    printf("\nFrase 2: ");
    
    for(int x = strlen(frase[1]) - 1; x >= 0; x--) printf("%c", frase[1][x]);

    printf("\n\n");

    // --------------------------- //

    system("pause");

    return 0;
}