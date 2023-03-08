#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

// ---------------------------------------------------------------------------------------------------------------------- //

struct infoBanda
{
	char nome[30], estilo[20];
	int numIntegrantes, topRank;
};

typedef struct infoBanda infoBanda;

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	// ----------------- //
	
	int numBandas = 5;

	infoBanda bandas[numBandas];

	for(int x = 0; x != numBandas; x++)
	{
		printf("[Banda %i]\n", x + 1);
		
		printf("> Digite o nome: ");
		scanf(" %[^\n]s", &bandas[x].nome);

		printf("> Digite o estilo musical: ");
		scanf(" %[^\n]s", &bandas[x].estilo);

		printf("> Digite a quantidade de integrantes: ");
		scanf("%i", &bandas[x].numIntegrantes);

		printf("> Digite a posição do rank: ");
		scanf("%i", &bandas[x].topRank);

		printf("\n");
	}

	printf("--------------------------------------------------------------\n\n");

	for(int x = 0; x != numBandas; x++)
	{
		printf("[Banda %i]\n\n", x + 1);

		printf("Nome: %s\nEstilo: %s\nNúmero de integrantes: %i\nPosição no rank: %iª\n\n", bandas[x].nome, bandas[x].estilo, bandas[x].numIntegrantes, bandas[x].topRank);
	}

	printf("\n--------------------------------------------------------------\n\n");

	char favorita[30];

	printf("> Digite o nome de uma banda: ");
	scanf(" %[^\n]s", &favorita);

	int achou = 0;

	for(int x = 0; x != numBandas; x++)
	{
		if(bandas[x].topRank <= 5)
		{
			if(!strcmp(favorita, bandas[x].nome))
			{
				achou = 1;
				break;
			}
		}
	}

	printf("\nA banda %s %s entre uma das favoritas.\n\n", favorita, achou ? "está" : "não está");

	// ----------------- // 
	    
	system("pause");

	// ----------------- // 
	
	return(0);
}