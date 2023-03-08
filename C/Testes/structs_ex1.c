#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int random(int interval)
{
	return rand() % interval;
}

int minrand(int min, int max)
{
	return random(max - min) + min;
}

char *getPosicao(int posicao)
{
	switch(posicao)
	{
		case 0: return "Goleiro";
		case 1: return "Artilheiro";
		case 2: return "Lateral";
		case 3: return "Zagueiro";
		case 4: return "Meio-campo";
	}
}

// ---------------------------------------------------------------------------------------------------------------------- //

struct atletas
{
	char nome[30];
	int posicao, faltas, gols;
};

typedef struct atletas Atleta;

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	// ----------------- // 
	
	Atleta time[11];

	for(int x = 0; x != 11; x++)
	{
		time[x].posicao = minrand(0, 5);
		time[x].faltas = minrand(0, 10);
		time[x].gols = minrand(0, 3);

		char aux[10];

		itoa(x, aux, 10);

		strcpy(time[x].nome, "Jogador ");
		strcat(time[x].nome, aux);

		printf("%s - %s - %i/%i\n", time[x].nome, getPosicao(time[x].posicao), time[x].gols, time[x].faltas);
	}

	int melhor = 0;

	for(int x = 0; x != 11; x++)
	{
		if(time[x].posicao == 1)
		{
			if(time[x].gols > time[melhor].gols) melhor = x;
		}
	}

	printf("\nMelhor artilheiro: %s - %i gols\n\n", time[melhor].nome, time[melhor].gols);

	// ----------------- // 
	    
	system("pause");

	// ----------------- // 
	
	return(0);
}