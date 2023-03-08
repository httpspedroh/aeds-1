#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	setlocale(LC_ALL, "Portuguese");

	// ----------------- // 
	
	FILE *file1, *file2, *file3;

	file1 = fopen("file1.txt", "r");

	if(file1 == NULL) return printf("x Ocorreu um erro ao abrir o arquivo \"file1.txt\"!");

	file3 = fopen("file3.txt", "w+");

	// ----------------- // 
	 
	char name_f1[20], name_f1_res[20], name_f2[20];

	while(fgets(name_f1, 20, file1) != NULL)
	{
		char menor_name[20];

		name_f1[strlen(name_f1) - 1] = '\0';

		FILE *file2 = fopen("file2.txt", "r");

		while(fgets(name_f2, 20, file2) != NULL)
		{
			name_f2[strlen(name_f2) - 1] = '\0';

			bool encontrou = false;

			for(int x = 0; x != strlen(name_f1); x++)
			{
				if(encontrou) break;

				for(int y = 0; y != strlen(name_f2); y++)
				{
					if(name_f1[x] < name_f2[y]) 
					{
						strcpy(menor_name, name_f1);
						encontrou = true;
						break;
					}
					else if(name_f1[x] > name_f2[y]) 
					{
						strcpy(menor_name, name_f2);
						encontrou = true;
						break;
					}
				}
			}

			printf("Comparar %s com %s = %s\n", name_f1, name_f2, menor_name);
		}

		fclose(file2);

		printf("================= FINAL: %s\n", menor_name);
	}

	printf("\n\n");

	fclose(file1);
	fclose(file2);
	fclose(file3);

	// ----------------- // 
	    
	system("pause");

	return(0);
}