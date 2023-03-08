#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

struct pessoa
{
	char nome[30];
	float altura;
};

typedef struct pessoa pessoa;

struct nascimento
{
	int dia, mes, ano;
};

typedef struct nascimento nascimento;

// ---------------------------------------------------------------------------------------------------------------------- //

int random(int interval)
{
	return rand() % interval;
}

int minrand(int min, int max)
{
	return random(max - min) + min;
}

void dataAleatorias(nascimento *data)
{
	data -> dia = minrand(1, 31);
	data -> mes = minrand(1, 12);
	data -> ano = minrand(1950, 2002);
}

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	// ----------------- // 
	
	pessoa pessoas[10];
	nascimento dataNasc[10];

	for(int x = 0; x != 10; x++)
	{
		printf("[Pessoa %i]\n", x + 1);

		printf("> Insira o nome: ");
		scanf(" %[^\n]s", &pessoas[x].nome);

		printf("> Insira a altura: ");
		scanf("%f", &pessoas[x].altura);

		dataAleatorias(&dataNasc[x]);

		printf("\n");
	}

	printf("--------------------------------------------------------------\n\n");

	for(int x = 0; x != 10; x++)
	{
		printf("[Pessoa %i]\n\n", x + 1);

		printf("Nome: %s\nAltura: %.2fm\nNascimento: %02i/%02i/%04i\n\n", pessoas[x].nome, pessoas[x].altura, dataNasc[x].dia, dataNasc[x].mes, dataNasc[x].ano);
	}

	// ----------------- // 
	    
	system("pause");

	// ----------------- // 
	
	return(0);
}