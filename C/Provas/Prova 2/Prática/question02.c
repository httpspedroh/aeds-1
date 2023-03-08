#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

void inicializarVec(char *vetor)
{
	for(int x = 0; x != 26; x++) *(vetor + x) = x + 65;
}

void lerVec(char *vetor)
{
	for(int x = 0; x != 26; x++) printf("%c", *(vetor + x));

	printf("\n\n");
}

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	// ----------------- // 
	
	char vetor[26];
	
	inicializarVec(vetor);
	lerVec(vetor);

	// ----------------- // 
	    
	system("pause");

	// ----------------- // 
	
	return(0);
}