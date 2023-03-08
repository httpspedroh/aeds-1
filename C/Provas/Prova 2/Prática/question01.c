#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

struct infoTitular
{
	char *nome, *cpf;
	float saldo;
};

typedef struct infoTitular infoTitular;

// ---------------------------------------------------------------------------------------------------------------------- //

void transferencia(infoTitular *contaEnvia, infoTitular *contaRecebe, float valor)
{
	if(contaEnvia -> saldo < valor) printf("\nx Quantia insuficiente!\n\n");
	else
	{
		contaRecebe -> saldo += valor;
		contaEnvia -> saldo -= valor;

		printf("\n[Conta que enviou]\nNome: %s\nSaldo atual: %.2f\n\n[Conta que recebeu]\nNome: %s\nSaldo atual: %.2f\n\n", contaEnvia -> nome, contaEnvia -> saldo, contaRecebe -> nome, contaRecebe -> saldo);
	}
}

#define numContas 2

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	// ----------------- // 

	infoTitular contas[numContas] = 
	{
		"Pedro", "11341633632", 4700.00,
		"Daniel", "05581015694", 5300.00,
	};

	char e_cpf_str[15], r_cpf_str[15];
	int idEnviar = -1, idReceber = -1;
	float quantia;

	do
	{
		printf("Insira o CPF da conta que irá enviar (sem pontuação): ");
		scanf(" %[^\n]s", e_cpf_str);

		for(int x = 0; x != numContas; x++) if(!strcmp(contas[x].cpf, e_cpf_str)) idEnviar = x;

		if(idEnviar == -1) printf("x Conta inexistente!\n\n");
	} 
	while(idEnviar == -1);

	do
	{
		printf("Insira o CPF da conta que irá receber (sem pontuação): ");
		scanf(" %[^\n]s", r_cpf_str);

		for(int x = 0; x != numContas; x++) if(!strcmp(contas[x].cpf, r_cpf_str)) idReceber = x;

		if(idReceber == -1) printf("x Conta inexistente!\n\n");
		if(idReceber == idEnviar) printf("x A conta que irá receber não pode ser a mesma!\n\n");
	}
	while(idReceber == -1 || idReceber == idEnviar);

	printf("Insira o valor do PIX alegre: ");
	scanf("%f", &quantia);

	transferencia(contas + idEnviar, contas + idReceber, quantia);

	// ----------------- // 
	    
	system("pause");

	// ----------------- // 
	
	return(0);
}