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

    float vetor_f[10] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};

    for(int x = 0; x != 10; x++) printf("vetor_f[%i] = %x\n", x, vetor_f + x);
    
    printf("\n\n");

    // --------------------------- //

    system("pause");

    return 0;
}