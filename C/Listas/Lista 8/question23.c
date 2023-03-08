#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char string[50];
    int posicao[2] = {-1, -1};

    printf("> Digite a string: ");
    scanf(" %[^\n]s", &string);

    do
    {
        printf("> Digite a posição inicial (I): ");
        scanf("%i", &posicao[0]);
    } 
    while(posicao[0] == -1);

    do
    {
        printf("> Digite a posição final (J): ");
        scanf("%i", &posicao[1]);
    } 
    while(posicao[1] == -1);
    
    printf("\nResultado: ");

    for(int x = 0; x != strlen(string); x++)
    {
        if(x >= posicao[0] && x <= posicao[1]) printf("%c", string[x]);
    }

    printf("\n\n");

    // --------------------------- //

    system("pause");

    return 0;
}