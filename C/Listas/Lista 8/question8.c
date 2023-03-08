#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char string[25], count = 0;

    printf("> Digite a string: ");
    scanf(" %[^\n]s", &string);

    for(int x = 0; x != strlen(string); x++)
    {
        if(string[x] == 49) count++;
    }

    printf("\nTotal de 1's = %i\n\n", count);

    // --------------------------- //

    system("pause");

    return 0;
}