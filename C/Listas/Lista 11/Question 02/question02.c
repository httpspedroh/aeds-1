#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	setlocale(LC_ALL, "Portuguese");

	// ----------------- // 
	
	FILE *file;

	file = fopen("file1.txt", "r");

	if(file == NULL) return printf("x Ocorreu um erro ao abrir o arquivo \"file1.txt\"!");

	int espacos = 1;
	char c;

	do
	{
		c = fgetc(file);
		
		if(c == ' ') espacos++;
	}
	while(c != EOF);

	printf("> Quantidade de palavras no arquivo \"file1.txt\": %i\n\n", espacos);

	fclose(file);

	// ----------------- // 
	    
	system("pause");

	return(0);
}