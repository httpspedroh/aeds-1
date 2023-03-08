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

// ---------------------------------------------------------------------------------------------------------------------- //

struct pessoa
{
	char nome[30];
	int altura, peso;
};

typedef struct pessoa pessoa;

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	// ----------------- // 
	
	pessoa pessoas[5];

	for(int x = 0; x != 5; x++)
	{
		char aux[10];

		itoa(x, aux, 10);

		strcpy(pessoas[x].nome, "Pessoa ");
		strcat(pessoas[x].nome, aux);

		pessoas[x].altura = minrand(150, 200);
		pessoas[x].peso = minrand(50000, 150000);

		float peso_f = (float)pessoas[x].peso / 1000, altura_f = (float)pessoas[x].altura / 100;

		printf("%s - Altura: %.2fm | Peso: %.2fkg - IMC = %.2f\n", pessoas[x].nome, altura_f, peso_f, peso_f / altura_f);
	}

	int alta = 0, pesada = 0;

	for(int x = 0; x != 5; x++)
	{
		if(pessoas[x].altura > pessoas[alta].altura) alta = x;
		if(pessoas[x].peso > pessoas[pesada].peso) pesada = x;
	}

	printf("\nPessoa mais alta: %s (%.2fm)\n", pessoas[alta].nome, (float)pessoas[alta].altura / 100);
	printf("Pessoa mais pesada: %s (%.2fkg)\n\n", pessoas[pesada].nome, (float)pessoas[pesada].peso / 1000);

	// ----------------- // 
	    
	system("pause");

	// ----------------- // 
	
	return(0);
}