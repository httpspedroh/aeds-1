#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

// ---------------------------------------------------------------------------------------------------------------------- //

struct infoAluno
{
	int matricula;
	char nome[30];
	float nota[3], media;
};

typedef struct infoAluno infoAluno;

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	// ----------------- //
	
	int numAlunos = 2, numProvas = 3;

	infoAluno alunos[numAlunos];

	for(int x = 0; x != numAlunos; x++)
	{
		printf("[Aluno %i]\n", x + 1);
		
		printf("> Digite o nome: ");
		scanf(" %[^\n]s", &alunos[x].nome);

		printf("> Digite a matrícula: ");
		scanf("%i", &alunos[x].matricula);

		float tmpSoma = 0;

		for(int y = 0; y != numProvas; y++)
		{
			printf("> Digite a nota da prova %i: ", y + 1);
			scanf("%f", &alunos[x].nota[y]);

			tmpSoma += alunos[x].nota[y];
		}

		if(tmpSoma >= 6) printf("\n(APROVADO)\n");
		else printf("\n(REPROVADO)\n");

		alunos[x].media = tmpSoma / numProvas;

		printf("\n");
	}

	printf("--------------------------------------------------------------\n\n");

	int maiorNt = 0, maiorMd = 0, menorMd = 0;

	for(int x = 0; x != numAlunos; x++)
	{
		if(alunos[x].nota[0] > alunos[maiorNt].nota[0]) maiorNt = x;
		if(alunos[x].media > alunos[maiorMd].media) maiorMd = x;
		if(alunos[x].media < alunos[menorMd].media) menorMd = x;
	}

	printf("Aluno com maior nota na 1ª prova: %s (%.2f)\n", alunos[maiorNt].nome, alunos[maiorNt].nota[0]);
	printf("Aluno com maior média: %s (%.2f)\n", alunos[maiorMd].nome, alunos[maiorMd].media);
	printf("Aluno com menor média: %s (%.2f)\n\n", alunos[menorMd].nome, alunos[menorMd].media);

	// ----------------- // 
	    
	system("pause");

	// ----------------- // 
	
	return(0);
}