#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PESSOAS 10

// ---------------------------------------------------------------------------------------------------------------------- //

struct pessoa {
	char *nome, aprovado;
    int idade;
};

typedef struct pessoa pessoa;

// ---------------------------------------------------------------------------------------------------------------------- //

pessoa getMaisJovem(pessoa *arrayPessoas) {
	int maisJovem = 0;

	for(int i = 0; i != MAX_PESSOAS; i++) {
		pessoa pessoaLoop = arrayPessoas[i];
		pessoa pessoaJovem = arrayPessoas[maisJovem];

		if(pessoaLoop.idade < pessoaJovem.idade) maisJovem = i;
	}

	return arrayPessoas[maisJovem];
}

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {
	pessoa pessoas[MAX_PESSOAS];

	for(int i = 0; i != MAX_PESSOAS; i++) {
		printf("[Pessoa %i]\n", i + 1);

        char nome_scf[30];

        printf("> Insira o nome: ");
		scanf(" %[^\n]s", &nome_scf);

        pessoas[i].nome = malloc(strlen(nome_scf) + 1);
        strcpy(pessoas[i].nome, nome_scf);
		
		printf("> Insira a idade: ");
		scanf("%i", &pessoas[i].idade);

        char aprovado_n = "a";

        do {
            printf("> Aprovado? ('s' ou 'n'): ");
		    scanf(" %c", &aprovado_n);
        } 
        while(aprovado_n != 's' && aprovado_n != 'S' && aprovado_n != 'n' && aprovado_n != 'N');

        pessoas[i].aprovado = aprovado_n;

		printf("\n");
	}

	printf("--------------------------------------------------------------\n[MAIS JOVEM]\n\n");

	pessoa maisNova = getMaisJovem(pessoas);

	printf("Nome: %s\nIdade: %i\nAprovado: %s\n\n", maisNova.nome, maisNova.idade, maisNova.aprovado ? "Sim" : "Nao");

	// ----------------- // 
	
	return(0);
}