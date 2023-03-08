#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COUNT 500

// ---------------------------------------------------------------------------------------------------------------------- //

int random(int interval) { return rand() % interval; }
int minrand(int min, int max) { return random(max - min) + min; }

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {
	srand(time(NULL));
	
	// ----------------- // 

    FILE *file_numeros = fopen("Numeros.txt", "w+");

    for(int i = 0; i != NUM_COUNT; i++) {
        int num_r = minrand(0, 1000);

        for(int y = 0; num_r % 2 != 0; y++) num_r = minrand(0, 1000);

        fprintf(file_numeros, "%i\n", num_r);
    }

    fclose(file_numeros);

    printf("> Arquivo com 500 numeros criado com sucesso.\n\n");
	
	// ----------------- // 
	
	return(0);
}