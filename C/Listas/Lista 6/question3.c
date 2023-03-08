#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>

// -------------------------------------------------------------- //

int main() 
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------------- //

    // Questão 3
    float tempo_corredor[3][5];
    float tempo_total[5] = {0, 0, 0, 0, 0};

    for(int x = 0; x != 3; x++)
    {
        int melhor_etapa = 0;

        for(int y = 0; y != 5; y++)
        {
            do
            {
                printf("> [Etapa %i - Corredor %i] Digite o tempo: ", x + 1, y + 1);
                scanf("%f", &tempo_corredor[x][y]);
            } 
            while(tempo_corredor[x][y] <= 0);

            if(tempo_corredor[x][y] < tempo_corredor[x][melhor_etapa]) melhor_etapa = y;

            tempo_total[y] += tempo_corredor[x][y];
        }

        printf("> [Etapa %i - Vencedor] Corredor %i\n\n", x + 1, melhor_etapa + 1);
    }

    int melhor_geral = 0;

    for(int x = 0; x != 5; x++)
    {
        if(tempo_total[x] < tempo_total[melhor_geral]) melhor_geral = x;
    }

    printf("> VENCEDOR GERAL: Corredor %i (%.2f)\n\n", melhor_geral + 1, tempo_total[melhor_geral]);

    // ----------------------- //

	system("pause");
    return 0;
}