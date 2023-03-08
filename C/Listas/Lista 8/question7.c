#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char string[2][25], diferencas = 0;

    printf("> Digite a primeira string: ");
    scanf(" %[^\n]s", &string[0]);

    printf("> Digite a segunda string: ");
    scanf(" %[^\n]s", &string[1]);

    for(int x = 0; x != 25; x++)
    {
        if(string[0][x] != string[1][x]) diferencas++;
    }

    if(diferencas == 0) printf("\nAs strings são iguais\n\n");
    else printf("\nAs strings não são iguais\n\n");
  
    // --------------------------- //

    system("pause");

    return 0;
}