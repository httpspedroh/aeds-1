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

    srand(time(NULL));

    char p_i;
    int pont_pc = 0, pont_user = 0;

    for(int x = 0; x != 3; x++)
    {
        int usuario = 0;

        printf("------------------ Rodada %i ------------------\n\n", x + 1);

        do
        {
            printf("> Digite 'P' para par ou 'I' para ímpar: ");
            scanf(" %c", &p_i);
        } 
        while(p_i != 'p' && p_i != 'P' && p_i != 'i' && p_i != 'I');
    
        do
        {
            printf("> Digite o número inteiro desejado: ");
            scanf("%i", &usuario);
        } 
        while(usuario < 0);
        
        // -------- //

        printf("\n");

        int pc = rand();
        int soma = pc + usuario;

        if(soma % 2 == 0)
        {
            printf("Usuário: %i | PC: %i | Soma: %i\n", usuario, pc, soma);

            if(p_i == 'p' || p_i == 'P') pont_user++;
            else if(p_i == 'i' || p_i == 'I') pont_pc++;
        }
        else if(soma % 2 != 0)
        {
            printf("Usuário: %i | PC: %i | Soma: %i\n", usuario, pc, soma);

            if(p_i == 'i' || p_i == 'I') pont_user++;
            else if(p_i == 'p' || p_i == 'P') pont_pc++;
        }

        printf("\n");
    }

    printf("----------------------------------------------\n\n");

    printf("> VENCEDOR: %s (%i pontos)\n\n", pont_user > pont_pc ? "Usuário" : "Computador", pont_user > pont_pc ? pont_user : pont_pc);
    
    // ----------------------- //

	system("pause");
    return 0;
}