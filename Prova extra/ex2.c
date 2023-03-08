#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COUNT 500

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {
    FILE *file_numeros = fopen("Numeros.txt", "r");

    char line[20];
    int soma = 0, maior = 0, menor = 1000;

	while(fgets(line, 20, file_numeros) != NULL) {
		int numero = atoi(line);

        if(numero > maior) maior = numero;
        if(numero < menor) menor = numero;

        soma += numero;
	}

    fclose(file_numeros);

    printf("> Menor numero: %i\n> Maior numero: %i\n> Media: %.2f\n\n", menor, maior, (float)soma / (float)NUM_COUNT);

	// ----------------- // 
	
	return(0);
}