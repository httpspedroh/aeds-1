#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char string[50], letra1, letra2;

    printf("> Digite uma frase: ");
    scanf(" %[^\n]s", &string);

    printf("> Digite a letra 1: ");
    scanf(" %c", &letra1);

    printf("> Digite a letra 2: ");
    scanf(" %c", &letra2);

    for(int x = 0; x != strlen(string); x++) if(string[x] == letra1) string[x] = letra2;

    printf("\nResultado: %s\n\n", string);

    // --------------------------- //

    system("pause");

    return 0;
}