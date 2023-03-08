#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

// ---------------------------------------------------------------------------------------------------------------------- //

struct posicao2d
{
	float x, y;
};

typedef struct posicao2d posicao2d;

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	// ----------------- //
	
	posicao2d pontos[2];

	for(int x = 0; x != 2; x++)
	{
		printf("[Ponto %i]\n", x + 1);
		
		printf("> Digite a posição X: ");
		scanf("%f", &pontos[x].x);

		printf("> Digite a posição Y: ");
		scanf("%f", &pontos[x].y);

		printf("\n");
	}

	printf("--------------------------------------------------------------\n\n");

	for(int x = 0; x != 2 - 1; x++)
	{
		float raiz = pow(pontos[x].x - pontos[x + 1].x, 2) + pow(pontos[x].y - pontos[x + 1].y, 2);

		printf("Distâncias dos pontos (%i, %i) = sqrt(%.0f) = %.2f\n", x + 1, x + 2, raiz, sqrt(raiz));
	}

	printf("\n");

	// ----------------- // 
	    
	system("pause");

	// ----------------- // 
	
	return(0);
}