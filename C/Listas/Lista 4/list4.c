#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>

// -------------------------------------------------------------- //

// Exerc�cio 1
int par(int n)
{
    return n * 2;
}

void exercicio01()
{
    int valor_n;

    printf("1. Digite um valor inteiro N: ");
    scanf("%i", &valor_n);

    printf("1.R: %i� termo da sequ�ncia = %i\n\n", valor_n, par(valor_n));
}

// -------------------------------------------------------------- //

// Exerc�cio 2
void mostrarParesEmOrdemDecrescente(int n)
{
    printf("2.R: ");

    for(int x = n - 1; x > 0; x--)
    {
        if(x % 2 == 0) printf("%i ", par(x) / 2);
    }

    printf("\n\n");
}

void exercicio02()
{
    int valor_n;

    printf("2. Digite um valor inteiro N: ");
    scanf("%i", &valor_n);

    mostrarParesEmOrdemDecrescente(valor_n);
}

// -------------------------------------------------------------- //

// Exerc�cio 3
double umSobreImpar(int n)
{
    return (2 * n) + 1;
}

void exercicio03()
{
    int valor_n;

    printf("3. Digite um valor inteiro N: ");
    scanf("%i", &valor_n);

    printf("3.R: 1/%.0lf\n\n", umSobreImpar(valor_n));
}

// -------------------------------------------------------------- //

// Exerc�cio 4
double somaUmSobreImpar(int n)
{
    int numeradores = 0;
    double denominadores = 1;

    for(int x = 1; x != n + 1; x++) denominadores *= umSobreImpar(x);

    for(int x = 1; x != n + 1; x++)
    {
        int d_local = umSobreImpar(x);

        numeradores += (denominadores / d_local);
    }

    printf("4.R: Somat�rio (Fra��o): %i/%.0lf\n", numeradores, denominadores);
    return numeradores / denominadores;
}

void exercicio04()
{
    int valor_n;

    printf("4. Digite um valor inteiro N: ");
    scanf("%i", &valor_n);

    printf("4.R: Somat�rio: %.2lf\n\n", somaUmSobreImpar(valor_n));
}

// -------------------------------------------------------------- //

// Exerc�cio 5
double parSobreImpar(int n)
{
    printf("5.A: Resultado (Fra��o): %i/%.0lf\n", par(n), umSobreImpar(n));
    return par(n) / umSobreImpar(n);
}

double somaParSobreImpar(int n)
{
    int numeradores = 0;
    double denominadores = 1;

    for(int x = 1; x != n + 1; x++) denominadores *= umSobreImpar(x);

    for(int x = 1; x != n + 1; x++)
    {
        int n_local = par(x);
        int d_local = umSobreImpar(x);

        numeradores += (denominadores / d_local) * n_local;
    }

    printf("5.B: Somat�rio (Fra��o): %i/%.0lf\n", numeradores, denominadores);
    return numeradores / denominadores;
}

void exercicio05()
{
    int valor_n;

    printf("5. Digite um valor inteiro N: ");
    scanf("%i", &valor_n);

    printf("5.A: Resultado: %.2lf\n", parSobreImpar(valor_n));
    printf("5.B: Somat�rio: %.2lf\n\n", somaParSobreImpar(valor_n));
}

// -------------------------------------------------------------- //

double funcao06(int n, int x)
{
    printf("6.R: Resultado (Procedimento) = (%ix ^ %i) / %.0lf\n", par(n), n, umSobreImpar(n));
    return (par(n) * pow(x, n)) / umSobreImpar(n);
}

void exercicio06()
{
    int valor_n;
    float valor_x;

    printf("6. Digite um valor inteiro N e um real X, separados por espa�o: ");
    scanf("%i %f", &valor_n, &valor_x);
    
    printf("6.R: Resultado (Fun��o) = %.2lf\n\n", funcao06(valor_n, valor_x));
}

// -------------------------------------------------------------- //

double funcao07(int n, int x)
{
    double result = 1;

    for(int y = 1; y != n + 1; y++) result *= (par(y) * pow(x, y)) / umSobreImpar(y);
    return result;
}

void exercicio07()
{
    int valor_n;
    float valor_x;

    printf("7. Digite um valor inteiro N e um real X, separados por espa�o: ");
    scanf("%i %f", &valor_n, &valor_x);
    
    printf("7.R: Resultado = %.2lf\n\n", funcao07(valor_n, valor_x));
}

// -------------------------------------------------------------- //

double fatorial(int number)
{
	double total = number;

	for(int x = 1; x != number; x++) total *= number - x;
	return total;
}

void exercicio08()
{
    int valor_n;

    printf("8. Insira um valor N: ");
    scanf("%i", &valor_n);
    
    printf("8.R: Resultado de %i! = %.0lf\n\n", valor_n, fatorial(valor_n));
}

// -------------------------------------------------------------- //

double funcao09(int n, int x)
{
    return (par(n) * pow(x, n)) / fatorial(umSobreImpar(n));
}

void exercicio09()
{
    int valor_n;
    float valor_x;

    printf("9. Digite um valor inteiro N e um real X, separados por espa�o: ");
    scanf("%i %f", &valor_n, &valor_x);
    
    printf("9.R: Resultado (Fun��o) = %.2lf\n\n", funcao09(valor_n, valor_x));
}

// -------------------------------------------------------------- //

double funcao10(int n, int x)
{
    double result = 0;

    for(int y = 1; y != n + 1; y++) result += funcao09(y, x);

    return result;
}

void exercicio10()
{
    int valor_n;
    float valor_x;

    printf("10. Digite um valor inteiro N e um real X, separados por espa�o: ");
    scanf("%i %f", &valor_n, &valor_x);
    
    printf("10.R: Resultado (Somat�rio) = %.2lf\n\n", funcao10(valor_n, valor_x));
}

// -------------------------------------------------------------- //

double funcao11(int n, int x)
{
    double result = 0;

    for(int y = 1; y != n + 1; y++)
    {
        if((int)fatorial(umSobreImpar(y)) % 2 != 0) 
        {
            result += (par(y) * pow(x, y)) / fatorial(umSobreImpar(y));
        }
    }
    return result;
}

void exercicio11()
{
    int valor_n;
    float valor_x;

    printf("11. Digite um valor inteiro N e um real X, separados por espa�o: ");
    scanf("%i %f", &valor_n, &valor_x);
    
    printf("11.R: Resultado (Somat�rio) = %.2lf\n\n", funcao11(valor_n, valor_x));
}

// -------------------------------------------------------------- //

void funcao12(int n)
{
    printf("12.R: ");

    for(int x = 0; n > 0; x++)
    {
        if(x % 5 == 0)
        {
            printf("%i ", x);
            n--;
        }
    }

    printf("\n\n");
}

void exercicio12()
{
    int valor_n;

    printf("12. Digite um valor N: ");
    scanf("%i", &valor_n);
    
    funcao12(valor_n);
}

// -------------------------------------------------------------- //

void funcao13(int n)
{
    double anterior = 0, atual = 1;

    for(int x = 2; x < n; x++)
    {
        double old_atual = atual;

        atual += anterior;
        anterior = old_atual;

        if(x == n - 1) printf("13.R: %i� termo de Fibonacci: %.0f", n, atual);
    }

    printf("\n\n");
}

void exercicio13()
{
    int valor_n;

    printf("13. Digite um valor N: ");
    scanf("%i", &valor_n);
    
    funcao13(valor_n);
}

// -------------------------------------------------------------- //

void funcao14(int n)
{
    double anterior = 0, atual = 1;

    for(int x = 2; x < n; x++)
    {
        double old_atual = atual;

        atual += anterior;
        anterior = old_atual;

        if(atual > n) 
        {
            printf("14.R: Maior elemento menor que o %i: %.0f", n, anterior);
            break;
        }
    }

    printf("\n\n");
}

void exercicio14()
{
    int valor_n;

    printf("14. Digite um valor N: ");
    scanf("%i", &valor_n);
    
    funcao14(valor_n);
}

// -------------------------------------------------------------- //

int main() 
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------------- //

    // Exerc�cio 1
    exercicio01();

    // ----------------------- //

    // Exerc�cio 2
    exercicio02();

    // ----------------------- //

    // Exerc�cio 3
    exercicio03();  

    // ----------------------- //

    // Exerc�cio 4
    exercicio04();

    // ----------------------- //

    // Exerc�cio 5
    exercicio05();

    // ----------------------- //

    // Exerc�cio 6
    exercicio06();

    // ----------------------- //

    // Exerc�cio 7
    exercicio07();

    // ----------------------- //

    // Exerc�cio 8
    exercicio08();

    // ----------------------- //

    // Exerc�cio 9
    exercicio09();

    // ----------------------- //

    // Exerc�cio 10
    exercicio10();

    // ----------------------- //

    // Exerc�cio 11
    exercicio11();

    // ----------------------- //

    // Exerc�cio 12
    exercicio12();

    // ----------------------- //

    // Exerc�cio 13
    exercicio13();

    // ----------------------- //

    // Exerc�cio 14
    exercicio14();

    // ----------------------- //

	system("pause");
    return 0;
}