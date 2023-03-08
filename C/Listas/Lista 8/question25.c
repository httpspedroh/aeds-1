#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char palavra1[50], palavra2[50];

    printf("> Digite a palavra 1: ");
    scanf(" %[^\n]s", &palavra1);

    printf("> Digite a palavra 2: ");
    scanf(" %[^\n]s", &palavra2);

    for(int x = 0; x != 50; x++)
    {
        if(palavra1[x] != palavra2[x])
        {
            if(palavra1[x] < palavra2[x]) printf("\nA palavra \"%s\" vem primeiro na ordem alfabética.\n\n", palavra1);
            else printf("\nA palavra \"%s\" vem primeiro na ordem alfabética.\n\n", palavra2);
            break;
        }
    }

    // --------------------------- //

    system("pause");

    return 0;
}