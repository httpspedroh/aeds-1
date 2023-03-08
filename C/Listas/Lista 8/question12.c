#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char string[60], substituir;
    int count = 0;

    printf("> Digite uma palavra: ");
    scanf(" %[^\n]s", &string);

    printf("> Digite um caractere a substituir as vogais: ");
    scanf(" %c", &substituir);

    for(int x = 0; x != strlen(string); x++)
    {
        if(string[x] == 65 || string[x] == 69 || string[x] == 73 || string[x] == 79 || string[x] == 85 
        || string[x] == 97 || string[x] == 101 || string[x] == 105 || string[x] == 111 || string[x] == 117) 
        {
            count++;

            string[x] = substituir;
        }
    }

    printf("\nTotal de vogais: %i\n", count);
    printf("Substituindo: %s\n\n", string);

    // --------------------------- //

    system("pause");

    return 0;
}