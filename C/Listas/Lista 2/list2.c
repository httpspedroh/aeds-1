#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main() 
{
	setlocale(LC_ALL, "Portuguese");

    int number[3];
    float f_number[3], area;
    char carac[2];

	// ----------------------- //
    
    // Exerc�cio 1
    printf("1. Insira o primeiro n�mero inteiro: ");
    scanf("%f", &f_number[0]);

    printf("1. Insira o segundo n�mero inteiro: ");
    scanf("%f", &f_number[1]);
    
    printf("1.R A diferen�a entre os dois n�meros � de %i\n", abs(f_number[0] - f_number[1]));

    if(f_number[1] != 0) printf("1.R O resultado da divis�o � %.2f\n\n", f_number[0] / f_number[1]);
    else printf("1.R O segundo n�mero � 0 e n�o pode ser usado como denominador\n\n");

    // ----------------------- //
    
    // Exerc�cio 2
    printf("2. Insira um n�mero inteiro: ");
    scanf("%i", &number[0]);

    printf("2.R O n�mero %i %s divis�vel por 7\n\n", number[0], number[0] % 7 == 0 ? "�" : "n�o �");
 
    // ----------------------- //

    // Exerc�cio 3
    printf("3. Insira tr�s n�meros reais, separados por espa�o: ");
    scanf("%f %f %f", &f_number[0], &f_number[1], &f_number[2]);

    printf("3.R Os n�meros %.1f; %.1f e %.1f %s formar um tri�ngulo\n\n", f_number[0], f_number[1], f_number[2], (f_number[0] > abs(f_number[1] - f_number[2]) && f_number[0] < f_number[1] + f_number[2]) || (f_number[1] > abs(f_number[0] - f_number[2]) && f_number[1] < f_number[0] + f_number[2]) || (f_number[2] > abs(f_number[0] - f_number[1]) && f_number[2] < f_number[0] + f_number[1]) ? "podem" : "n�o podem");

    // ----------------------- //

    // Exerc�cio 4
    printf("4. Insira o primeiro coeficiente (a): ");
    scanf("%f", &f_number[0]);

    printf("4. Insira o segundo coeficiente (b): ");
    scanf("%f", &f_number[1]);

    printf("4.R Raiz = %.1f\n\n", -f_number[1] / f_number[0]);

    // ----------------------- //

    // Exerc�cio 5
    int pri_eq[3], seg_eq[3];

    printf("5. Insira a primeira equa��o, separando os componentes por espa�o: ");
    scanf("%i %i %i", &pri_eq[0], &pri_eq[1], &pri_eq[2]);

    printf("5. Insira a segunda equa��o, separando os componentes por espa�o: ");
    scanf("%i %i %i", &seg_eq[0], &seg_eq[1], &seg_eq[2]);

    if((pri_eq[0] == 0 && pri_eq[1] == 0 && pri_eq[2] != 0) || 
       (seg_eq[0] == 0 && seg_eq[1] == 0 && seg_eq[2] != 0) || 
       (pri_eq[0] == 1 && pri_eq[1] == 1 && seg_eq[0] == 1 && seg_eq[1] == 1 && pri_eq[2] != seg_eq[2])) printf("5.R Sem solu��o (SI)\n\n");
    else
    {
        int determinante = abs(pri_eq[0] * seg_eq[1]) - abs(pri_eq[1] * seg_eq[0]);

        if(determinante != 0) printf("5.R Infinitas solu��es (SPD)\n\n");
        else if(determinante == 0) printf("5.R Uma solu��o (SPI)\n\n");
    }

    // ----------------------- //

    // Exerc�cio 6
    printf("6. Insira a equa��o de segundo grau, separando os componentes por espa�o: ");
    scanf("%f %f %f", &f_number[0], &f_number[1], &f_number[2]);

    float delta = pow(f_number[1], 2) - (4 * f_number[0] * f_number[2]); // b�-4ac

    if(delta < 0) printf("6.R Ra�zes imagin�rias (Delta < 0)\n\n");
    else 
    {
        float x1 = (float)(-f_number[1] + sqrt(delta)) / (float)(2 * f_number[0]);
        float x2 = (float)(-f_number[1] - sqrt(delta)) / (float)(2 * f_number[0]);

        printf("6.R x1 = %.2f; x2 = %.2f (Delta >= 0)\n\n", x1, x2);
    }

    // ----------------------- //
    
    // Exerc�cio 7
    printf("7. Insira o primeiro n�mero real: ");
    scanf("%f", &f_number[0]);

    printf("7. Insira o segundo n�mero real: ");
    scanf("%f", &f_number[1]);

    if(f_number[0] > f_number[1]) printf("7.R O primeiro n�mero � maior: %.2f\n\n", f_number[0]);
    else if(f_number[1] > f_number[0]) printf("7.R O segundo n�mero � maior: %.2f\n\n", f_number[1]);
    else if(f_number[0] == f_number[1]) printf("7.R Os n�meros s�o iguais: %.2f e %.2f\n\n", f_number[0], f_number[1]);

    // ----------------------- //
    
    // Exerc�cio 8
    printf("8. Insira os lados do tri�ngulo, separados por espa�o: ");
    scanf("%i %i %i", &number[0], &number[1], &number[2]);

    if(!((number[0] > abs(number[1] - number[2]) && number[0] < number[1] + number[2]) || (number[1] > abs(number[0] - number[2]) && number[1] < number[0] + number[2]) || (number[2] > abs(number[0] - number[1]) && number[2] < number[0] + number[1]))) printf("8.R As medidas inseridas n�o podem formar um tri�ngulo.\n\n");
    else if((number[0] == number[1]) && (number[1] == number[2]) && (number[0] == number[2])) printf("8.R O tri�ngulo � um tri�ngulo equil�tero.\n\n");
    else if((number[0] != number[1]) && (number[1] != number[2]) && (number[0] != number[2])) printf("8.R O tri�ngulo � um tri�ngulo escaleno.\n\n");
    else if((number[0] == number[1] && number[2] != number[0] && number[2] != number[1]) || (number[1] == number[2] && number[0] != number[1] && number[0] != number[2]) || (number[0] == number[2] && number[1] != number[0] && number[1] != number[2])) printf("8.R O tri�ngulo � um tri�ngulo is�sceles.\n\n");

    // ----------------------- //
    
    // Exerc�cio 9
    printf("9. Insira os lados do tri�ngulo, separados por espa�o: ");
    scanf("%i %i %i", &number[0], &number[1], &number[2]);

    float ang_a, ang_b, ang_c;

    f_number[0] = (pow(number[0], 2) + pow(number[1], 2) - pow(number[2], 2)) / (2 * number[0] * number[1]);
    f_number[1] = (pow(number[0], 2) + pow(number[2], 2) - pow(number[1], 2)) / (2 * number[0] * number[2]);
    f_number[2] = (pow(number[1], 2) + pow(number[2], 2) - pow(number[0], 2)) / (2 * number[1] * number[2]);

    ang_a = acos(f_number[0]) * (180 / M_PI);
    ang_b = acos(f_number[1]) * (180 / M_PI);
    ang_c = acos(f_number[2]) * (180 / M_PI); 

    if(ang_a < 90 && ang_b < 90 && ang_c < 90) printf("9.R �ngulos: %0.f�, %.0f� e %.0f� (Acut�ngulo)\n\n", ang_a, ang_b, ang_c);
    else if(ang_a == 90 || ang_b == 90 || ang_c == 90) printf("9.R �ngulos: %0.f�, %.0f� e %.0f� (Ret�ngulo)\n\n", ang_a, ang_b, ang_c);
    else if(ang_a > 90 || ang_b > 90 || ang_c > 90) printf("9.R �ngulos: %0.f�, %.0f� e %.0f� (Obtus�ngulo)\n\n", ang_a, ang_b, ang_c);
    else printf("9.R Os lados apresentados n�o representam um tri�ngulo.\n\n");

    // ----------------------- //
    
    // Exerc�cio 10
    printf("10. Insira uma data no formato DD MM YYYY, separada por espa�os: ");
    scanf("%2d %2d %4d", &number[0], &number[1], &number[2]);

    if((number[2] % 4 == 0 && number[2] % 100 != 0) || number[2] % 400 == 0) printf("10.R O ano %i � bissexto.\n\n", number[2]);
    else printf("10.R O ano %i n�o � bissexto.\n\n", number[2]);

    // ----------------------- //
    
    // Exerc�cio 11
    printf("11. Insira o primeiro n�mero real: ");
    scanf("%f", &f_number[0]);

    printf("11. Insira o segundo n�mero real: ");
    scanf("%f", &f_number[1]);

    if(f_number[0] == f_number[1]) printf("11.R Os n�meros s�o iguais: %.2f e %.2f\n\n", f_number[0], f_number[1]);
    else printf("11.R Maior: %.2f | Menor: %.2f\n\n", f_number[0] > f_number[1] ? f_number[0] : f_number[1], f_number[0] < f_number[1] ? f_number[0] : f_number[1]);

    // ----------------------- //
    
    // Exerc�cio 12
    printf("12. Insira dois caracteres, separados por espa�o: ");
    scanf(" %c %c", &carac[0], &carac[1]);

    printf("12.R Ordem alfab�tica: %c %c\n\n", carac[0] < carac[1] ? carac[0] : carac[1], carac[1] < carac[0] ? carac[0] : carac[1]);

    // ----------------------- //
    
    // Exerc�cio 13
    printf("13. Digite o numerador e denominador, separados por espa�o: ");
	scanf("%f %f", &f_number[0], &f_number[1]);

    if(f_number[1] != 0) printf("13.R Resultado de %.2f/%.2f: %.2f\n\n", f_number[0], f_number[1], f_number[0] / f_number[1]);
    else printf("13.R O denominador � 0, portanto a opera��o � imposs�vel fora dos reais.\n\n");

    // ----------------------- //
    
    // Exerc�cio 14
    printf("14. Digite um n�mero real: ");
	scanf("%f", &f_number[0]);

    if(f_number[0] == 0) printf("14.R O n�mero � igual a 0.\n\n");
    else if(f_number[0] > 0) printf("14.R O n�mero � maior que 0.\n\n");
    else if(f_number[0] < 0) printf("14.R O n�mero � menor que 0.\n\n");

    // ----------------------- //
    
    // Exerc�cio 15
    printf("15. Digite um n�mero inteiro: ");
	scanf("%i", &number[0]);

    if(number[0] % 2 == 0) printf("15.R %i� = %.0f\n\n", number[0], pow(number[0], 2));
    else printf("15.R %i� = %.0f\n\n", number[0], pow(number[0], 3));

    // ----------------------- //
    
    // Exerc�cio 16
    printf("16. Digite um n�mero inteiro: ");
	scanf("%i", &number[0]);

    if(number[0] == 1 || number[0] == 2) 
    {
        printf("16. Digite os lados do ret�ngulo, separados por espa�o: ");
        scanf("%f %f", &f_number[0], &f_number[1]);

        float diagonal = sqrt(pow(f_number[0], 2) + pow(f_number[1], 2));
        float raio = diagonal / 2;
        
        area = M_PI * pow(raio, 2);

        printf("16.R �rea do c�rculo circunscrito: %.2f\n\n", area);
    }
    else if(number[0] == 3 || number[0] == 4 || number[0] == 5) 
    {
        printf("16. Digite o raio do c�rculo: ");
        scanf("%f", &f_number[0]);

        float lado = f_number[0] * sqrt(2);
        
        area = pow(lado, 2);

        printf("16.R �rea do quadrado inscrito: %.2f\n\n", area);
    }
    else
    {
        printf("16. Digite o lado do quadrado: ");
        scanf("%f", &f_number[0]);

        float r_menor, r_maior;

        r_menor = f_number[0] / 2;
        r_maior = f_number[0] / sqrt(2);

        printf("16.R �rea da coroa circular: %.2f\n\n", M_PI * (r_menor + r_maior) * (r_maior - r_menor));
    }

    // ----------------------- //
    
    // Exerc�cio 17
    float lado, altura;

    printf("17. Digite um caractere e o raio do c�rculo, separados por espa�o: ");
	scanf(" %c %f", &carac[0], &f_number[0]);

    if(carac[0] == 't' || carac[0] == 'T')
    {
        lado = f_number[0] * sqrt(3);
        altura = lado * (sqrt(3) / 2);
        area = (lado * altura) / 2;

        printf("17.R �rea do tri�ngulo inscrito = %.2f\n\n", area);
    }
    else if(carac[0] == 'q' || carac[0] == 'Q')
    {
        lado = f_number[0] * sqrt(2);
        area = pow(lado, 2);

        printf("17.R �rea do quadrado inscrito = %.2f\n\n", area);
    }
    else if(carac[0] == 'h' || carac[0] == 'H')
    {
        area = (3 * pow(f_number[0], 2) * sqrt(3)) / 2;

        printf("17.R �rea do hex�gono inscrito = %.2f\n\n", area);
    }
    else printf("17.R Caractere inv�lido! Insira os caracteres T, Q ou H.\n\n");

    // ----------------------- //
    
	system("pause");
	return 0;
}