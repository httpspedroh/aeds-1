#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char nome[10][30];
	int idade[10];

    for(int x = 0; x != 10; x++)
    {
        printf("[Pessoa %i]\n", x + 1);

        printf("> Digite o primeiro nome: ");
		scanf(" %[^\n]s", &nome[x]);

        printf("> Digite a idade: ");
        scanf("%i", &idade[x]);

		printf("\n");
    }

    int velho = 0, novo = 0;

	for(int x = 0; x != 10; x++)
	{
		if(idade[x] > idade[velho]) velho = x;
		if(idade[x] < idade[novo]) novo = x;
	}

	printf("[Mais velho]\nNome: %s\nIdade: %i\n\n", nome[velho], idade[velho]);
	printf("[Mais novo]\nNome: %s\nIdade: %i\n\n", nome[novo], idade[novo]);

    // --------------------------- //

    system("pause");

    return 0;
}