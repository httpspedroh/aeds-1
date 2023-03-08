#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>

// -------------------------------------------------------------- //

bool isPrimoIntern(int n, int i)
{
    if(n <= 2) return n == 2 ? true : false;
    if(n % i == 0) return false;
    if(i * i > n) return true;
    else return isPrimoIntern(n, i + 1);
}

bool isPrimo(int n)
{
    return isPrimoIntern(n, 2);
}

// -------------------------------------------------------------- //

int random(int interval)
{
	return rand() % interval;
}

// -------------------------------------------------------------- //

int main() 
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    // ----------------------- //

    // Questão 5
    int values[9];

    for(int x = 0; x != 9; x++)
    {
        values[x] = random(200);

        if(isPrimo(values[x])) printf("> Valor %i = %i [PRIMO]\n", x + 1, values[x]);
        else printf("> Valor %i = %i\n", x + 1, values[x]);
    }
    
    printf("\n\n");

    // ----------------------- //

	system("pause");
    return 0;
}