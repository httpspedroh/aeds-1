#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	setlocale(LC_ALL, "Portuguese");

	// ----------------- // 
	
	char fileName[30];

	printf("> Digite o nome do arquivo desejado: ");
	scanf(" %[^\n]s", fileName);

	// ----------------- // 
	
	FILE *file;

	file = fopen(fileName, "r");

	if(file == NULL) return printf("\nx Ocorreu um erro ao abrir o arquivo \"%s\"!\n\n", fileName);
	else printf("\n> Arquivo: ");

	// ----------------- // 
	
	int caracs = 0;
	char c;

	c = fgetc(file);

	do
	{
		printf("%c", c);

		caracs++;

		c = fgetc(file);
	}
	while(c != EOF);

	printf("\n> Total de caracteres: %i\n\n", caracs);

	fclose(file);

	// ----------------- // 
	    
	system("pause");

	return(0);
}