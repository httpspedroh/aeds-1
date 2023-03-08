#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

struct infoTelefone
{
	int ddd, numero;
};

typedef struct infoTelefone infoTelefone;

struct infoNasc
{
	int dia, mes, ano;
};

typedef struct infoNasc infoNasc;

struct infoContato
{
	char nome[30], email[50], observacoes[40];

	infoTelefone telefone;
	infoNasc dataNasc;
};

typedef struct infoContato infoContato;

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	// ----------------- // 
	
	infoContato contatos[5] = 
	{
		"Pedro", "pedro.costa.1362465@sga.pucminas.br", "Mlk neutro", {37, 998750433}, {29, 4, 2002},
		"Daniel", "daniel.capanema@pucminas.br", "Gosta de Fibonacci", {31, 999975434}, {13, 2, 1993},
		"Jane", "jane@gmail.com", "Nada", {37, 998733561}, {16, 2, 2002}
	};

	int opcao, qtdCtt = 3, resultados = 0;

	MenuPrincipal:

	printf("\n--------------------------------------------------------------\n\n");

	printf("1. Buscar primeiro nome\n2. Buscar mês de aniversário\n3. Inserir pessoa\n4. Visualizar nomes, telefones e emails\n5. Visualizar toda a agenda\n\nDigite a opção: ");
	scanf("%i", &opcao);

	printf("\n--------------------------------------------------------------\n");

	if(opcao == 1)
	{
		char busca[30];

		printf("\nDigite o nome a se buscar: ");
		scanf(" %[^\n]s", &busca);

		for(int x = 0; x != strlen(contatos); x++)
		{
			if(!strcmp(contatos[x].nome, busca))
			{
				printf("\nNome: %s\nEmail: %s\nObservações: %s\nTelefone: (%i) %i\nData de nascimento: %02i/%02i/%04i\n", contatos[x].nome, contatos[x].email, contatos[x].observacoes, contatos[x].telefone.ddd, contatos[x].telefone.numero, contatos[x].dataNasc.dia, contatos[x].dataNasc.mes, contatos[x].dataNasc.ano);

				resultados++;
			}
		}

		if(resultados == 0) printf("\nNenhum resultado encontrado!\n");

		goto MenuPrincipal;
	}
	else if(opcao == 2)
	{
		int mesBusca;

		printf("\nDigite o número do mês a se buscar: ");
		scanf("%i", &mesBusca);

		for(int x = 0; x != strlen(contatos); x++)
		{
			if(contatos[x].dataNasc.mes == mesBusca)
			{
				printf("\nNome: %s\nEmail: %s\nObservações: %s\nTelefone: (%i) %i\nData de nascimento: %02i/%02i/%04i\n", contatos[x].nome, contatos[x].email, contatos[x].observacoes, contatos[x].telefone.ddd, contatos[x].telefone.numero, contatos[x].dataNasc.dia, contatos[x].dataNasc.mes, contatos[x].dataNasc.ano);

				resultados++;
			}
		}

		if(resultados == 0) printf("\nNenhum resultado encontrado!\n");

		goto MenuPrincipal;
	}
	else if(opcao == 3)
	{
		if(qtdCtt == 5)
		{
			printf("\nA agenda está cheia!\n");

			goto MenuPrincipal;
		}

		printf("\nInsira o nome da pessoa: ");
		scanf(" %[^\n]s", &contatos[qtdCtt].nome);

		printf("Insira o email da pessoa: ");
		scanf(" %[^\n]s", &contatos[qtdCtt].email);

		printf("Insira observações: ");
		scanf(" %[^\n]s", &contatos[qtdCtt].observacoes);

		printf("Insira o telefone, com DDD separado por espaço: ");
		scanf("%i %i", &contatos[qtdCtt].telefone.ddd, &contatos[qtdCtt].telefone.numero);

		printf("Insira a data de nascimento, separada por espaços: ");
		scanf("%i %i %i", &contatos[qtdCtt].dataNasc.dia, &contatos[qtdCtt].dataNasc.mes, &contatos[qtdCtt].dataNasc.ano);

		qtdCtt++;

		goto MenuPrincipal;
	}
	else if(opcao == 4)
	{
		for(int x = 0; x != qtdCtt; x++)
		{
			printf("\nNome: %s\nEmail: %s\nTelefone: (%i) %i\n", contatos[x].nome, contatos[x].email, contatos[x].telefone.ddd, contatos[x].telefone.numero);
		}

		goto MenuPrincipal;
	}
	else if(opcao == 5)
	{
		for(int x = 0; x != qtdCtt; x++)
		{
			printf("\nNome: %s\nEmail: %s\nObservações: %s\nTelefone: (%i) %i\nData de nascimento: %02i/%02i/%04i\n", contatos[x].nome, contatos[x].email, contatos[x].observacoes, contatos[x].telefone.ddd, contatos[x].telefone.numero, contatos[x].dataNasc.dia, contatos[x].dataNasc.mes, contatos[x].dataNasc.ano);
		}

		goto MenuPrincipal;
	}
	else
	{
		printf("\nx Opção inválida!\n");

		goto MenuPrincipal;
	}

	// ----------------- // 
	    
	system("pause");

	// ----------------- // 
	
	return(0);
}