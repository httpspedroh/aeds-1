#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char veiculo[5][20];
    int consumo[5];

    for(int x = 0; x != 5; x++)
    {
        printf("[Carro %i]\n\n", x + 1);

        printf("Digite o modelo: ");
        scanf(" %[^\n]s", &veiculo[x]);

        printf("Digite o consumo (km/L): ");
        scanf("%i", &consumo[x]);

        printf("\n");
    }

    printf("------------------------------------------\n\n");

    int economico = 0;
    
    for(int x = 0; x != 5; x++) if(consumo[x] > consumo[economico]) economico = x;

    for(int x = 0; x != 5; x++)
    {
        printf("Veículo: %s%s", veiculo[x], economico == x ? " (MAIS ECONÔMICO)\n" : "\n");
        printf("Consumo em 1000km: %.2fL\n\n", (float)1000 / (float)consumo[x]);
    }

    // --------------------------- //

    system("pause");

    return 0;
}