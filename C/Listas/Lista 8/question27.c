#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

void remove_nChar(char string[]) 
{
    int remover = 0;

    for(int x = 0; x <= strlen(string); x++)
    {
        string[x - remover] = string[x];

        if(!((string[x] >= 'a' && string[x] <= 'z') || (string[x] >= 'A' && string[x] <= 'Z'))) remover++;
    }
}

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char frase[50];

    printf("> Digite a frase: ");
    scanf(" %[^\n]s", &frase);

    remove_nChar(frase);

    int i = 0, j = strlen(frase) - 1;
    bool result = true;
 
    while(j > i)
    {
        if(frase[i++] != frase[j--])
        {
            printf("\nA frase não é um palíndromo.\n\n");
            result = false;
            break;
        }
    }

    if(result == true) printf("\nA frase é um palíndromo.\n\n");

    // --------------------------- //

    system("pause");

    return 0;
}