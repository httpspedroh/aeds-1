#include <stdio.h>
#include <locale.h>
#include <conio.h>

// ---------------------------------------------------------------------------------------------------------------------- //

void trocarVogais(char *frase)
{
    for(int x = 0; x != strlen(frase); x++)
    {
        if(*(frase + x) == 'a') *(frase + x) = 'u';
        else if(*(frase + x) == 'e') *(frase + x) = 'o';
        else if(*(frase + x) == 'i') *(frase + x) = 'u';
        else if(*(frase + x) == 'o') *(frase + x) = 'a';
        else if(*(frase + x) == 'u') *(frase + x) = 'e';
    }
}

// ---------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char frase[100];

    printf("Digite a frase desejada: ");
    scanf(" %[^\n]s", &frase);

    printf("\nAntes: %s", frase);

    trocarVogais(&frase);

    printf("\nDepois: %s\n\n", frase);

    // --------------------------- //

    system("pause");

    return 0;
}