#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>

// -------------------------------------------------------------- //

// Exerc�cio 1
int funcao1(int n)
{
    int resp = 1;

    if(n > 0)
	{
		resp = n * funcao1(n - 1);
	}
    return resp;
}

// Exerc�cio 2
float funcao2(int n)
{
    float resp = 0;

    if(n == 1) resp = 2;
    else if(n == 2) resp = 3;
    else if(n >= 3)
	{
		resp = (5 * n) + pow(funcao2(n - 1), n);
	}
    return resp;
}

// Exerc�cio 3
int funcao3(int n)
{
    int resp = 0;

    if(n > 0) resp = n + funcao3(n - 1);
    return resp;
}

// Exerc�cio 4
void funcao4(int n)
{
    if(n > 0)
    {
        funcao4(n / 2);

        printf("%i", n % 2);
    }
}

// Exerc�cio 5
int funcao5(int n, int y)
{
	int soma = 0;

	if(y > 0)
	{
		soma = n + funcao5(n, y - 1);
	}
	return soma;
}

// Exerc�cio 6
int funcao6(int n, int y)
{
    int mdc = 0;

    if(y == 0) mdc = n;
	else
	{
		mdc = funcao6(y, n % y);
	}
	return mdc;
}

// Exerc�cio 7
int funcao7(int n)
{
    int count = 1;

    if(n >= 10)
    {
        n /= 10;
        count += funcao7(n);
    }
	return count;
}

// Exerc�cio 8
bool funcao8(int n, int i)
{
    if(n <= 2) return n == 2 ? true : false;
    if(n % i == 0) return false;
    if(i >= n / 2) return true; // if(i * i > n)
    else return funcao8(n, i + 1);
}

// -------------------------------------------------------------- //

int main() 
{
    setlocale(LC_ALL, "Portuguese");

    int valor_n, valor_y;

    // ----------------------- //

    // Exerc�cio 1
    printf("1. Insira um valor N: ");
    scanf("%i", &valor_n);

    printf("1.R: Resultado de %i! = %i\n\n", valor_n, funcao1(valor_n));

    // ----------------------- //

    // Exerc�cio 2
    printf("2. Insira um valor N: ");
    scanf("%i", &valor_n);

    printf("2.R: Resultado = %.0f\n\n", funcao2(valor_n));

    // ----------------------- //

    // Exerc�cio 3
    printf("3. Insira um valor N: ");
    scanf("%i", &valor_n);

    printf("3.R: Resultado = %i\n\n", funcao3(valor_n));

    // ----------------------- //

    // Exerc�cio 4
    printf("4. Insira um valor N: ");
    scanf("%i", &valor_n);

    printf("4.R: ");

    funcao4(valor_n);

    printf("\n\n");

    // ----------------------- //

    // Exerc�cio 5
    printf("5. Insira dois valores a serem multiplicados, separados por espa�o: ");
    scanf("%i %i", &valor_n, &valor_y);

    printf("5.R: Resultado = %i\n\n", funcao5(valor_n, valor_y));

    // ----------------------- //

    // Exerc�cio 6
    printf("6. Insira dois valores, separados por espa�o: ");
    scanf("%i %i", &valor_n, &valor_y);

    printf("6.R: MDC de %i e %i = %i\n\n", valor_n, valor_y, funcao6(valor_n, valor_y));

    // ----------------------- //

    // Exerc�cio 7
    printf("7. Insira um n�mero: ");
    scanf("%i", &valor_n);

    printf("7.R: O n�mero %i tem %i d�gitos\n\n", valor_n, funcao7(valor_n));

    // ----------------------- //

    // Exerc�cio 8
    printf("8. Insira um n�mero: ");
    scanf("%i", &valor_n);

    printf("8.R: O n�mero %i %s primo.\n\n", valor_n, funcao8(valor_n, 2) == true ? "�" : "n�o �");

    // ----------------------- //

	system("pause");
    return 0;
}