#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char string[100];

    printf("> Digite a frase: ");
    scanf(" %[^\n]s", &string);

    int len = strlen(string), n1 = 0, n2 = 1, n3;

    printf("\nTamanho da frase = %i\n\n", len);

    if(len >= 1) printf("0 = %c\n", string[0]);
    if(len >= 2) printf("1 = %c\n", string[1]);

    for(int x = len; x > 2; x--)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        
        if(n3 < len) printf("%i = %c\n", n3, string[n3]);
    }
    
    printf("\n");

    // --------------------------- //

    system("pause");

    return 0;
}