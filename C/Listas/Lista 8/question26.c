#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char frase[80];

    printf("> Digite a frase: ");
    scanf(" %[^\n]s", &frase);

    int tam = 3;

    for(int x = 0; x != strlen(frase); x++) 
    {
        if(frase[x] != ' ') 
        {
            if(frase[x] >= 97 && frase[x] <= 122) // Minúsculo
            {
                frase[x] = ((frase[x] - 97 + tam) % 26) + 97;
            }
            else if(frase[x] >= 65 && frase[x] <= 122) // Maiúsculo
            {
                frase[x] = ((frase[x] - 65 + tam) % 26) + 65;
            }
        }
    }

    printf("\nFrase codificada: %s\n\n", frase);

    // --------------------------- //

    system("pause");

    return 0;
}