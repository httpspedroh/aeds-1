#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>

// ------------------------------------------------------------------------------ //

int random(int interval)
{
	return rand() % interval;
}

int minrand(int min, int max)
{
	return random(max - min) + min;
}

// ------------------------------------------------------------------------------ //

int main() {

	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");

    // ------------------------------------ //

	int qtdPlayers;

	printf("> Insira a quantidade de jogadores: ");
	scanf("%i", &qtdPlayers);

    int sorteados[6], escolhidos[qtdPlayers][6];

	for(int x = 0; x != 6; x++)
	{
		sorteados[x] = minrand(1, 60);

		for(int y = 0; y != x; y++)
		{
			if(sorteados[y] == sorteados[x]) 
			{
				x--;
				break;
			}
		}
	}

	for(int x = 0; x != qtdPlayers; x++)
	{
		for(int y = 0; y != 6; y++)
		{
			escolhidos[x][y] = minrand(1, 60);

			for(int z = 0; z != y; z++)
			{
				if(escolhidos[x][z] == escolhidos[x][y]) 
				{
					y--;
					break;
				}
			}
		}
	}

	// ------------------------------------ //

	for(int x = 0; x != qtdPlayers; x++)
	{
		printf("\n[Jogador %i]\n", x + 1);

		for(int y = 0; y != 6; y++) printf("Número %i = %i\n", y + 1, escolhidos[x][y]);
	}

	printf("\n---------------------------------------------------\n\n> Números sorteados:\n\n");

	for(int x = 0; x != 6; x++) printf("Número %i = %i\n", x + 1, sorteados[x]);

	printf("\n---------------------------------------------------\n\n> Acertos:\n\n");

	int acertos[qtdPlayers], melhor = 0;

	for(int x = 0; x != qtdPlayers; x++)
	{
		acertos[x] = 0;

		for(int y = 0; y != 6; y++)
		{
			for(int z = 0; z != 6; z++) if(escolhidos[x][y] == sorteados[z]) acertos[x]++;
		}

		if(acertos[x] > acertos[melhor]) melhor = x;

		printf("Jogador %i: %i acertos\n", x + 1, acertos[x]);
	}

	printf("\n");

	for(int x = 0; x != qtdPlayers; x++)
	{
		if(acertos[x] == acertos[melhor]) printf("> MELHOR: Jogador %i (%i acertos)\n", x + 1, acertos[melhor]);
	}
	return 0;
}