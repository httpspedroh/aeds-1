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

    printf("> Digite uma string: ");
    scanf(" %[^\n]s", &string);

    printf("\nSem vogais: ");

    for(int x = 0; x != strlen(string); x++)
    {
        if(string[x] != 65 && string[x] != 69 && string[x] != 73 && string[x] != 79 && string[x] != 85 
        && string[x] != 97 && string[x] != 101 && string[x] != 105 && string[x] != 111 && string[x] != 117) printf("%c", string[x]);
    }

    printf("\n\n");

    // --------------------------- //

    system("pause");

    return 0;
}