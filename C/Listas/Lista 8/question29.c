#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char string[2][50];

    printf("> Digite a primeira string: ");
    scanf(" %[^\n]s", &string[0]);

    printf("> Digite a segunda string: ");
    scanf(" %[^\n]s", &string[1]);

    int n = -1;

    do
    {
        printf("> Digite um valor positivo N: ");
        scanf("%i", &n);
    }
    while(n < 0);

    int len = strlen(string[0]);

    for(int x = 0; x != n; x++) 
    {
        string[0][len + x] = string[1][x];
    }

    string[0][len + n] = '\0';

    printf("\nResultado: %s\n\n", string[0]);

    // --------------------------- //

    system("pause");

    return 0;
}