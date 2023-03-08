#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>

#define NUM_CANDIDATOS 200

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

int main() 
{
    setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	// ----------------- // 
	
    FILE *file_votes = fopen("Votacao.txt", "w+");

    for(int x = 0; x != NUM_CANDIDATOS; x++) fprintf(file_votes, "%i\n", random(200));

    fclose(file_votes);

    // ----------------- // 
	    
	system("pause");

    return 0;
}