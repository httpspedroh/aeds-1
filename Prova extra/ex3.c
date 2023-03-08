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

	printf("--------------------------------------------------------------\n[APROVADOS]\n\n");

	for(int i = 0; i != MAX_PESSOAS; i++) {
        if(pessoas[i].aprovado == 's' || pessoas[i].aprovado == 'S')
		    printf("Nome: %s\nIdade: %i\nAprovado: %s\n\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].aprovado ? "Sim" : "Nao");
	}

	// ----------------- // 
	
	return(0);
}