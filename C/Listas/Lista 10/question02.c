#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

struct infoBolsa
{
	char nome[30], area[20];
	float acao_hj, acao_ant;
	double variacao;
};

typedef struct infoBolsa infoBolsa;

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	// ----------------- // 
	
	infoBolsa empresas[2];

	for(int x = 0; x != 2; x++)
	{
		printf("[Empresa %i]\n", x + 1);

		printf("> Insira o nome: ");
		scanf(" %[^\n]s", &empresas[x].nome);

		printf("> Insira o area de atua��o: ");
		scanf(" %[^\n]s", &empresas[x].area);

		printf("> Insira o valor atual da a��o: ");
		scanf("%f", &empresas[x].acao_hj);

		printf("> Insira o valor anterior da a��o: ");
		scanf("%f", &empresas[x].acao_ant);

		printf("\n");
	}

	printf("--------------------------------------------------------------\n\n");

	for(int x = 0; x != 2; x++)
	{
		printf("[Empresa %i]\n\n", x + 1);

		empresas[x].variacao = ((empresas[x].acao_hj - empresas[x].acao_ant) / empresas[x].acao_ant) * 100;

		printf("Nome: %s\n�rea: %s\nA��o anterior: R$%.2f\nA��o atual: R$%.2f\nVaria��o: %.4lf%%\n\n", empresas[x].nome, empresas[x].area, empresas[x].acao_ant, empresas[x].acao_hj, empresas[x].variacao);
	}

	// ----------------- // 
	    
	system("pause");

	// ----------------- // 
	
	return(0);
}