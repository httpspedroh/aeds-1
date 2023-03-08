#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>

// -------------------------------------------------------------- //

int random(int interval)
{
	return rand() % interval;
}

int minrand(int min, int max)
{
	return random(max - min) + min;
}

const char* getMonthName(int number) 
{
    switch(number)
    {
        case 1: return "Janeiro";
        case 2: return "Fevereiro";
        case 3: return "Março";
        case 4: return "Abril";
        case 5: return "Maio";
        case 6: return "Junho";
        case 7: return "Julho";
        case 8: return "Agosto";
        case 9: return "Setembro";
        case 10: return "Outrubro";
        case 11: return "Novembro";
        case 12: return "Dezembro";
    }
}

// -------------------------------------------------------------- //

int main() 
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    // ----------------------- //

    // Questão 15
    float vendas[12][4], totalMes[12], totalAno = 0;
    int melhorMes = 0;

    for(int x = 0; x != 12; x++)
    {
        totalMes[x] = 0;

        for(int y = 0; y != 4; y++)
        {
            vendas[x][y] = minrand(10000, 100000);

            printf("%.0f ", vendas[x][y]);

            totalMes[x] += vendas[x][y];
            totalAno += vendas[x][y];
        }

        if(totalMes[x] > totalMes[melhorMes]) melhorMes = x;

        printf("[%s - Total = R$%.0f]", getMonthName(x + 1), totalMes[x]);
        printf("\n");
    }

    printf("\n> Total do ano: R$%.0f\n> Melhor mês para comprar: %s\n\n", totalAno, getMonthName(melhorMes + 1));

    // ----------------------- //

	system("pause");
    return 0;
}