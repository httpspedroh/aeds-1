#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main() {

	// ----------------------- //

	int number;

	printf("1. Digite um n�mero inteiro de 3 d�gitos: ");
	scanf("%i", &number);
	
	int primeiro_a = number / 100;
	int segundo_a = (number % 100) / 10;
	int terceiro_a = (number % 100) % 10;

	printf("1.R: O n�mero ao contr�rio � %i%i%i\n\n", terceiro_a, segundo_a, primeiro_a);

	// ----------------------- //

	float salario_min, consumed;

	printf("2.1 Digite o valor do sal�rio m�nimo: ");
	scanf("%f", &salario_min);

	printf("2.2 Digite a quantidade de kilowatts consumidos: ");
	scanf("%f", &consumed);
	
	float kilowatt = (salario_min / 7.0f) / 100.0f;

	printf("2.R: O valor a ser pago � de R$%.2f\n2.R: O valor com 10%% de desconto � de R$%.2f\n\n", kilowatt * consumed, (kilowatt * consumed) * 0.9);

	// ----------------------- //

	int base, height;

	printf("3.1 Digite a medida da base do ret�ngulo: ");
	scanf("%i", &base);
 
	printf("3.2 Digite a medida da altura do ret�ngulo: ");
	scanf("%i", &height);
	
	printf("3.R: Per�metro: %d\n3.R: �rea: %d\n3.R: Diagonal: %.2f\n\n", (base * 2) + (height * 2), base * height, sqrt(pow(base, 2) + pow(height, 2)));

	// ----------------------- //

	float radius;

	printf("4. Digite o raio do c�rculo: ");
	scanf("%f", &radius);
 
	printf("4.R: Per�metro: %.2f\n4.R: �rea: %.2f\n\n", (2 * M_PI * radius), (M_PI * pow(radius, 2)));

	// ----------------------- //

	float lado_quadrado;

	printf("5. Digite a medida do lado do quadrado: ");
	scanf("%f", &lado_quadrado);
 
	printf("5.R: Per�metro: %.0f\n5.R: �rea: %.0f\n5.R: Diagonal: %.2f\n\n", lado_quadrado * 4, pow(lado_quadrado, 2), lado_quadrado * sqrt(2));

	// ----------------------- //

	float a = 0, b = 0, c = 0;

	printf("6. Digite os valores de a, b e c separados por espa�o: ");
	scanf("%f %f %f", &a, &b, &c);

	printf("6.R: y = %.2f\n\n", a + (b / (c + a)) + (2 * (a - b)) + (log2(64)));

	// ----------------------- //

	float cat_a, cat_o;

	printf("7. Digite os valores do cateto oposto e adjacente, separados por espa�o: ");
	scanf("%f %f", &cat_o, &cat_a);

	printf("7.R: Hipotenusa = %.2f\n\n", sqrt(pow(cat_a, 2) + pow(cat_o, 2)));

	// ----------------------- //

	int pa_first, pa_razao;

	printf("8. Digite o primeiro termo e a raz�o da P.A, separados por espa�o: ");
	scanf("%i %i", &pa_first, &pa_razao);

	printf("8.R: D�cimo termo = %i\n\n", pa_first + (9 * pa_razao));

	// ----------------------- //

	float pg_first, pg_razao;

	printf("9. Digite o primeiro termo e a raz�o da P.G, separados por espa�o: ");
	scanf("%f %f", &pg_first, &pg_razao);

	printf("9.R: Quinto termo = %.0f\n\n", pg_first * (pow(pg_razao, 4)));

	// ----------------------- //

	float r_a, r_b, new_a, new_b;

	printf("10. Digite dois valores reais A e B, separados por espa�o: ");
	scanf("%f %f", &r_a, &r_b);

	new_a = r_b;
	new_b = r_a;

	printf("10.R: Valores finais: A = %.2f, B = %.2f\n\n", new_a, new_b);

	// ----------------------- //

	float numerador, denominador;

	printf("11. Digite o numerador e denominador, separados por espa�o: ");
	scanf("%f %f", &numerador, &denominador);

	printf("11.R: Fra��o em decimal = %.2f\n\n", numerador / denominador);

	// ----------------------- //

	int hours, minutes;

	printf("12. Digite a hora e minuto base, separados por espa�o: ");
	scanf("%i %i", &hours, &minutes);

	printf("12.R: Minutos passados desde o in�cio do dia: %i\n\n", (hours * 60) + minutes);

	// ----------------------- //

	float receive_salario;

	printf("13. Insira o sal�rio m�nimo atual: ");
	scanf("%f", &salario_min);

	printf("13. Insira o seu sal�rio atual: ");
	scanf("%f", &receive_salario);

	printf("13.R: Voc� recebe %.1f sal�rios m�nimos.\n\n", receive_salario / salario_min);

	// ----------------------- //
	
	system("pause");
	return 0;
}