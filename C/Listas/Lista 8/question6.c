#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() 
{
    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char string[25], sexo;
    int idade;

    printf("> Digite um nome: ");
    scanf("%[^\n]s", &string);

    printf("> Digite o sexo: (M ou F) ");
    scanf(" %c", &sexo);

    printf("> Digite a idade: ");
    scanf("%i", &idade);

    if((sexo == 'F' || sexo == 'f') && idade < 25) printf("\n%s ACEITA\n\n", string);
    else printf("\n%s NÃO ACEITA\n\n", string);
  
    // --------------------------- //

    system("pause");

    return 0;
}