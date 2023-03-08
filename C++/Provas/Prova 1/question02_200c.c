#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>

#define NUM_CANDIDATOS 200

// ---------------------------------------------------------------------------------------------------------------------- //

int main() 
{
    setlocale(LC_ALL, "Portuguese");

	// ----------------- // 
	
    FILE *file_votes = fopen("Votacao.txt", "r");
    int qtd_votos[NUM_CANDIDATOS], vencedor = 0, qtd_segundot = 0;

    for(int x = 0; x != NUM_CANDIDATOS; x++) qtd_votos[x] = 0;

    char text[20];

	while(fgets(text, 20, file_votes) != NULL) 
	{
		int cdt = atoi(text);

        qtd_votos[cdt - 1]++;
	}

    fclose(file_votes);

    for(int x = 0; x != NUM_CANDIDATOS; x++) if(qtd_votos[x] > qtd_votos[vencedor]) vencedor = x;
    for(int x = 0; x != NUM_CANDIDATOS; x++) if(qtd_votos[x] == qtd_votos[vencedor]) qtd_segundot++;

    printf("[RESULTADOS DA VOTAÇÃO]\n\n");
        
    if(qtd_segundot <= 1)
    {
        printf("Candidato %i (%i votos) [VENCEDOR]\n", vencedor + 1, qtd_votos[vencedor]);

        for(int x = 0; x != NUM_CANDIDATOS; x++) if(x != vencedor) printf("Candidato %i (%i votos)\n", x + 1, qtd_votos[x]);
    }
    else
    {
        for(int x = 0; x != NUM_CANDIDATOS; x++) 
        {
            if(qtd_votos[x] == qtd_votos[vencedor]) printf("Candidato %i (%i votos) [SEGUNDO TURNO]\n", x + 1, qtd_votos[x]);
            else if(qtd_votos[x] != qtd_votos[vencedor]) printf("Candidato %i (%i votos)\n", x + 1, qtd_votos[x]);
        }
    }

    printf("\n");

    // ----------------- // 
	    
	system("pause");

    return 0;
}