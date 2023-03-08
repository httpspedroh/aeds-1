#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char string[25];

    printf("> Digite uma palavra: ");
    scanf(" %[^\n]s", &string);

    printf("\nAo contrário: ");

    for(int x = strlen(string) - 1; x >= 0; x--) printf("%c", string[x]);
    
    printf("\n\n");

    // --------------------------- //

    system("pause");

    return 0;
}