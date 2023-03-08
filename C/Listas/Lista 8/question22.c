#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

    setlocale(LC_ALL, "Portuguese");

	// --------------------------- //

    char produto[50];
    float preco = 0;

    printf("> Digite o nome do produto: ");
    scanf(" %[^\n]s", &produto);

    printf("> Digite o preço do produto: ");
    scanf("%f", &preco);

    printf("\nProduto: %s\nValor: R$%.2f\nValor à vista: R$%.2f\n\n", produto, preco, preco * 0.9);

    // --------------------------- //

    system("pause");

    return 0;
}