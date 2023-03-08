#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>

// -------------------------------------------------------------- //

// -------------------------------------------------------------- //

int main() 
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------------- //

    // Exerc�cio 2
    float salario_bruto = 0, prestacao_desejada = 0;

    do
    {
        printf("2. Insira o valor bruto do seu sal�rio: ");
        scanf("%f", &salario_bruto);

        printf("2. Insira o valor desejado da presta��o: ");
        scanf("%f", &prestacao_desejada);
    } 
    while(salario_bruto <= 0 || prestacao_desejada <= 0);
    
    int possivel = prestacao_desejada < (salario_bruto * 0.3);

    printf("\n2.R: %s voc� %s realizar o empr�stimo com pagamento em parcelas de R$%.2f\n", possivel == 1 ? "Parab�ns," : "Infelizmente", possivel == 1 ? "poder�" : "n�o poder�", prestacao_desejada);
    printf("2.R: Parcela m�xima permitida: R$%.2f\n\n", (salario_bruto * 0.3));
    
    // ----------------------- //

	system("pause");
    return 0;
}