#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	setlocale(LC_ALL, "Portuguese");

	// ----------------- // 
	
	FILE *file1 = fopen("file1.txt", "r"),
	*file2 = fopen("file2.txt", "r"),
	*file3 = fopen("file3.txt", "w+");

	if(file1 == NULL) return printf("x Ocorreu um erro ao abrir o arquivo \"file1.txt\"!");
	if(file2 == NULL) return printf("x Ocorreu um erro ao abrir o arquivo \"file2.txt\"!");

	// ----------------- // 
	 
	char name_f1[20], name_f2[20];
	int count = 0, nameCount = 10;
	char nomes[nameCount][20];

	while(fgets(name_f1, 20, file1) != NULL)
	{
		name_f1[strlen(name_f1) - 1] = '\0';

		printf("%s\n", name_f1);

		strcpy(nomes[count++], name_f1);
	}

	while(fgets(name_f2, 20, file2) != NULL)
	{
		name_f2[strlen(name_f2) - 1] = '\0';

		printf("%s\n", name_f2);

		strcpy(nomes[count++], name_f2);
	}

	printf("\n");

	char temp[20];

	for(int i = 0; i != nameCount; i++)
	{
		for(int j = 0; j < nameCount - 1 - i; j++)
		{
			if(strcmp(nomes[j], nomes[j + 1]) > 0)
			{
				strcpy(temp, nomes[j]);
				strcpy(nomes[j], nomes[j + 1]);
				strcpy(nomes[j + 1], temp);
			}
		}
	}

	printf("> Ordem alfabética:\n\n");

	for(int x = 0; x != nameCount; x++)
	{
		printf("%i: %s\n", x + 1, nomes[x]);

		strcat(nomes[x], "\n");
		fputs(nomes[x], file3);
	}

	printf("\n> Arquivo \"file3.txt\" criado com sucesso.\n\n");

	fclose(file1);
	fclose(file2);
	fclose(file3);

	// ----------------- // 
	    
	system("pause");

	return(0);
}