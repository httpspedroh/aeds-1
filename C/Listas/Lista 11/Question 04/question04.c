#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	setlocale(LC_ALL, "Portuguese");

	// ----------------- // 
	
	char s_oFile[30], s_cFile[30];

	GetOriginalFile:

	printf("> Digite o nome do arquivo original: ");
	scanf(" %[^\n]s", s_oFile);

	FILE *o_file;

	o_file = fopen(s_oFile, "r");

	if(o_file == NULL)
	{
		printf("x Ocorreu um erro ao abrir o arquivo \"%s\"!\n\n", s_oFile);
		goto GetOriginalFile;
	}

	printf("> Digite o nome do novo arquivo: ");
	scanf(" %[^\n]s", s_cFile);

	FILE *c_file;

	c_file = fopen(s_cFile, "w+");

	// ----------------- // 

	printf("\n> Conteúdo: ");
	
	char c;

	while((c = fgetc(o_file) ) != EOF) 
	{
		printf("%c", c);

		fputc(c, c_file);
	}
	
	printf("\n> Arquivo \"%s\" copiado com sucesso!\n\n", s_oFile);
	
	fclose(o_file);
	fclose(c_file);

	// ----------------- // 
	    
	system("pause");

	return(0);
}