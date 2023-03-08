#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char string[50];

    printf("> Digite uma frase: ");
    scanf(" %[^\n]s", &string);

    printf("\nResultado: ");

    for(int x = 0; x != strlen(string); x++) if(string[x] != ' ') printf("%c", string[x]);

    printf("\n\n");

    // --------------------------- //

    system("pause");

    return 0;
}