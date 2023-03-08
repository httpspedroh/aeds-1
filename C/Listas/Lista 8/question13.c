#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char string[60];
    int count = 0;

    printf("> Digite uma frase: ");
    scanf(" %[^\n]s", &string);

    for(int x = 0; x != strlen(string); x++) if(string[x] == ' ') count++;

    printf("\nTotal de espaços em branco: %i\n\n", count);

    // --------------------------- //

    system("pause");

    return 0;
}