#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	setlocale(LC_ALL, "Portuguese");

	// ----------------- // 
	
	FILE *file = fopen("file.txt", "r");

	if(file == NULL) return printf("\nx Ocorreu um erro ao abrir o arquivo \"file.txt\"!\n\n");

	// ----------------- // 

	char text[20];
	float soma = 0, menor = INFINITE, maior = 0;
	int linhas = 0;

	while(fgets(text, 20, file) != NULL) 
	{
		float value = atof(text);

		soma += value;

		if(value > maior) maior = value;
		if(value < menor) menor = value;

		linhas++;
	}

	fclose(file);

	printf("> Menor valor: %.4f\n> Maior valor: %.4f\n> Média dos valores: %.4f\n\n", menor, maior, soma / (float)linhas);

	// ----------------- // 
	    
	system("pause");

	return(0);
}