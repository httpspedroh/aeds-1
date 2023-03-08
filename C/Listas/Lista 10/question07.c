#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

// ---------------------------------------------------------------------------------------------------------------------- //

struct infoFuncionario
{
	char nome[30], sexo, cargo[30];
	int idade, nascDia, nascMes, nascAno, setor;
	float salario;
};

typedef struct infoFuncionario infoFuncionario;

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	// ----------------- //
	
	int numFunc = 5;

	infoFuncionario funcionarios[numFunc];

	for(int x = 0; x != numFunc; x++)
	{
		printf("[Funcionário %i]\n", x + 1);
		
		printf("> Digite o nome: ");
		scanf(" %[^\n]s", &funcionarios[x].nome);

		printf("> Digite o sexo (M/F): ");
		scanf(" %c", &funcionarios[x].sexo);

		printf("> Digite o cargo: ");
		scanf(" %[^\n]s", &funcionarios[x].cargo);
		
		printf("> Digite a data de nascimento, separada por espaços: ");
		scanf("%i %i %i", &funcionarios[x].nascDia, &funcionarios[x].nascMes, &funcionarios[x].nascAno);

		printf("> Digite o setor (0-99): ");
		scanf("%i", &funcionarios[x].setor);

		printf("> Digite o salário: ");
		scanf("%f", &funcionarios[x].salario);

		printf("\n");
	}

	printf("--------------------------------------------------------------\n\n");

	for(int x = 0; x != numFunc; x++)
	{
		printf("[Funcionário %i]\n\n", x + 1);

		printf("Nome: %s\nSexo: %c\nCargo: %s\nNascimento: %02i/%02i/%04i (%i anos)\nSetor: %i\nSalário: %.2f\n\n", funcionarios[x].nome, funcionarios[x].sexo, funcionarios[x].cargo, funcionarios[x].nascDia, funcionarios[x].nascMes, funcionarios[x].nascAno, 2021 - funcionarios[x].nascAno, funcionarios[x].setor, funcionarios[x].salario);	
	}

	// ----------------- // 
	    
	system("pause");

	// ----------------- // 
	
	return(0);
}