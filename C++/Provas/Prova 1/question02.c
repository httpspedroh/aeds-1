#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() 
{
    setlocale(LC_ALL, "Portuguese");

	// ----------------- // 
	
    FILE *file_votes = fopen("Votacao.txt", "r");
    int qtd_votos[4] = {0, 0, 0, 0}, vencedor = 0, qtd_segundot = 0;

    char c;

    while(c != EOF)
    {
        c = fgetc(file_votes);
        
        if(c == '1') qtd_votos[0]++;
        else if(c == '2') qtd_votos[1]++;
        else if(c == '3') qtd_votos[2]++;
        else if(c == '4') qtd_votos[3]++;
    }

    fclose(file_votes);

    for(int x = 0; x != 4; x++) if(qtd_votos[x] > qtd_votos[vencedor]) vencedor = x;
    for(int x = 0; x != 4; x++) if(qtd_votos[x] == qtd_votos[vencedor]) qtd_segundot++;

    printf("[RESULTADOS DA VOTAÇÃO]\n\n");
        
    if(qtd_segundot <= 1)
    {
        printf("Candidato %i (%i votos) [VENCEDOR]\n", vencedor + 1, qtd_votos[vencedor]);

        for(int x = 0; x != 4; x++) if(x != vencedor) printf("Candidato %i (%i votos)\n", x + 1, qtd_votos[x]);
    }
    else
    {
        for(int x = 0; x != 4; x++) if(qtd_votos[x] == qtd_votos[vencedor]) printf("Candidato %i (%i votos) [SEGUNDO TURNO]\n", x + 1, qtd_votos[x]);

        for(int x = 0; x != 4; x++) if(qtd_votos[x] != qtd_votos[vencedor]) printf("Candidato %i (%i votos)\n", x + 1, qtd_votos[x]);

        printf("\n");
    }

    printf("\n");

    // ----------------- // 
	    
	system("pause");

    return 0;
}