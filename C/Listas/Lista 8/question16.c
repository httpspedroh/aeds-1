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

    for(int x = 0; x != strlen(string); x++) if(string[x] >= 97 && string[x] <= 122) string[x] -= 32;

    printf("\nResultado: %s\n\n", string);

    // --------------------------- //

    system("pause");

    return 0;
}