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
    
    // Exercício 1
    printf("1. Insira o primeiro número inteiro: ");
    scanf("%f", &f_number[0]);

    printf("1. Insira o segundo número inteiro: ");
    scanf("%f", &f_number[1]);
    
    printf("1.R A diferença entre os dois números é de %i\n", abs(f_number[0] - f_number[1]));

    if(f_number[1] != 0) printf("1.R O resultado da divisão é %.2f\n\n", f_number[0] / f_number[1]);
    else printf("1.R O segundo número é 0 e não pode ser usado como denominador\n\n");

    // ----------------------- //
    
    // Exercício 2
    printf("2. Insira um número inteiro: ");
    scanf("%i", &number[0]);

    printf("2.R O número %i %s divisível por 7\n\n", number[0], number[0] % 7 == 0 ? "é" : "não é");
 
    // ----------------------- //

    // Exercício 3
    printf("3. Insira três números reais, separados por espaço: ");
    scanf("%f %f %f", &f_number[0], &f_number[1], &f_number[2]);

    printf("3.R Os números %.1f; %.1f e %.1f %s formar um triângulo\n\n", f_number[0], f_number[1], f_number[2], (f_number[0] > abs(f_number[1] - f_number[2]) && f_number[0] < f_number[1] + f_number[2]) || (f_number[1] > abs(f_number[0] - f_number[2]) && f_number[1] < f_number[0] + f_number[2]) || (f_number[2] > abs(f_number[0] - f_number[1]) && f_number[2] < f_number[0] + f_number[1]) ? "podem" : "não podem");

    // ----------------------- //

    // Exercício 4
    printf("4. Insira o primeiro coeficiente (a): ");
    scanf("%f", &f_number[0]);

    printf("4. Insira o segundo coeficiente (b): ");
    scanf("%f", &f_number[1]);

    printf("4.R Raiz = %.1f\n\n", -f_number[1] / f_number[0]);

    // ----------------------- //

    // Exercício 5
    int pri_eq[3], seg_eq[3];

    printf("5. Insira a primeira equação, separando os componentes por espaço: ");
    scanf("%i %i %i", &pri_eq[0], &pri_eq[1], &pri_eq[2]);

    printf("5. Insira a segunda equação, separando os componentes por espaço: ");
    scanf("%i %i %i", &seg_eq[0], &seg_eq[1], &seg_eq[2]);

    if((pri_eq[0] == 0 && pri_eq[1] == 0 && pri_eq[2] != 0) || 
       (seg_eq[0] == 0 && seg_eq[1] == 0 && seg_eq[2] != 0) || 
       (pri_eq[0] == 1 && pri_eq[1] == 1 && seg_eq[0] == 1 && seg_eq[1] == 1 && pri_eq[2] != seg_eq[2])) printf("5.R Sem solução (SI)\n\n");
    else
    {
        int determinante = abs(pri_eq[0] * seg_eq[1]) - abs(pri_eq[1] * seg_eq[0]);

        if(determinante != 0) printf("5.R Infinitas soluções (SPD)\n\n");
        else if(determinante == 0) printf("5.R Uma solução (SPI)\n\n");
    }

    // ----------------------- //

    // Exercício 6
    printf("6. Insira a equação de segundo grau, separando os componentes por espaço: ");
    scanf("%f %f %f", &f_number[0], &f_number[1], &f_number[2]);

    float delta = pow(f_number[1], 2) - (4 * f_number[0] * f_number[2]); // b²-4ac

    if(delta < 0) printf("6.R Raízes imaginárias (Delta < 0)\n\n");
    else 
    {
        float x1 = (float)(-f_number[1] + sqrt(delta)) / (float)(2 * f_number[0]);
        float x2 = (float)(-f_number[1] - sqrt(delta)) / (float)(2 * f_number[0]);

        printf("6.R x1 = %.2f; x2 = %.2f (Delta >= 0)\n\n", x1, x2);
    }

    // ----------------------- //
    
    // Exercício 7
    printf("7. Insira o primeiro número real: ");
    scanf("%f", &f_number[0]);

    printf("7. Insira o segundo número real: ");
    scanf("%f", &f_number[1]);

    if(f_number[0] > f_number[1]) printf("7.R O primeiro número é maior: %.2f\n\n", f_number[0]);
    else if(f_number[1] > f_number[0]) printf("7.R O segundo número é maior: %.2f\n\n", f_number[1]);
    else if(f_number[0] == f_number[1]) printf("7.R Os números são iguais: %.2f e %.2f\n\n", f_number[0], f_number[1]);

    // ----------------------- //
    
    // Exercício 8
    printf("8. Insira os lados do triângulo, separados por espaço: ");
    scanf("%i %i %i", &number[0], &number[1], &number[2]);

    if(!((number[0] > abs(number[1] - number[2]) && number[0] < number[1] + number[2]) || (number[1] > abs(number[0] - number[2]) && number[1] < number[0] + number[2]) || (number[2] > abs(number[0] - number[1]) && number[2] < number[0] + number[1]))) printf("8.R As medidas inseridas não podem formar um triângulo.\n\n");
    else if((number[0] == number[1]) && (number[1] == number[2]) && (number[0] == number[2])) printf("8.R O triângulo é um triângulo equilátero.\n\n");
    else if((number[0] != number[1]) && (number[1] != number[2]) && (number[0] != number[2])) printf("8.R O triângulo é um triângulo escaleno.\n\n");
    else if((number[0] == number[1] && number[2] != number[0] && number[2] != number[1]) || (number[1] == number[2] && number[0] != number[1] && number[0] != number[2]) || (number[0] == number[2] && number[1] != number[0] && number[1] != number[2])) printf("8.R O triângulo é um triângulo isósceles.\n\n");

    // ----------------------- //
    
    // Exercício 9
    printf("9. Insira os lados do triângulo, separados por espaço: ");
    scanf("%i %i %i", &number[0], &number[1], &number[2]);

    float ang_a, ang_b, ang_c;

    f_number[0] = (pow(number[0], 2) + pow(number[1], 2) - pow(number[2], 2)) / (2 * number[0] * number[1]);
    f_number[1] = (pow(number[0], 2) + pow(number[2], 2) - pow(number[1], 2)) / (2 * number[0] * number[2]);
    f_number[2] = (pow(number[1], 2) + pow(number[2], 2) - pow(number[0], 2)) / (2 * number[1] * number[2]);

    ang_a = acos(f_number[0]) * (180 / M_PI);
    ang_b = acos(f_number[1]) * (180 / M_PI);
    ang_c = acos(f_number[2]) * (180 / M_PI); 

    if(ang_a < 90 && ang_b < 90 && ang_c < 90) printf("9.R Ângulos: %0.f°, %.0f° e %.0f° (Acutângulo)\n\n", ang_a, ang_b, ang_c);
    else if(ang_a == 90 || ang_b == 90 || ang_c == 90) printf("9.R Ângulos: %0.f°, %.0f° e %.0f° (Retângulo)\n\n", ang_a, ang_b, ang_c);
    else if(ang_a > 90 || ang_b > 90 || ang_c > 90) printf("9.R Ângulos: %0.f°, %.0f° e %.0f° (Obtusângulo)\n\n", ang_a, ang_b, ang_c);
    else printf("9.R Os lados apresentados não representam um triângulo.\n\n");

    // ----------------------- //
    
    // Exercício 10
    printf("10. Insira uma data no formato DD MM YYYY, separada por espaços: ");
    scanf("%2d %2d %4d", &number[0], &number[1], &number[2]);

    if((number[2] % 4 == 0 && number[2] % 100 != 0) || number[2] % 400 == 0) printf("10.R O ano %i é bissexto.\n\n", number[2]);
    else printf("10.R O ano %i não é bissexto.\n\n", number[2]);

    // ----------------------- //
    
    // Exercício 11
    printf("11. Insira o primeiro número real: ");
    scanf("%f", &f_number[0]);

    printf("11. Insira o segundo número real: ");
    scanf("%f", &f_number[1]);

    if(f_number[0] == f_number[1]) printf("11.R Os números são iguais: %.2f e %.2f\n\n", f_number[0], f_number[1]);
    else printf("11.R Maior: %.2f | Menor: %.2f\n\n", f_number[0] > f_number[1] ? f_number[0] : f_number[1], f_number[0] < f_number[1] ? f_number[0] : f_number[1]);

    // ----------------------- //
    
    // Exercício 12
    printf("12. Insira dois caracteres, separados por espaço: ");
    scanf(" %c %c", &carac[0], &carac[1]);

    printf("12.R Ordem alfabética: %c %c\n\n", carac[0] < carac[1] ? carac[0] : carac[1], carac[1] < carac[0] ? carac[0] : carac[1]);

    // ----------------------- //
    
    // Exercício 13
    printf("13. Digite o numerador e denominador, separados por espaço: ");
	scanf("%f %f", &f_number[0], &f_number[1]);

    if(f_number[1] != 0) printf("13.R Resultado de %.2f/%.2f: %.2f\n\n", f_number[0], f_number[1], f_number[0] / f_number[1]);
    else printf("13.R O denominador é 0, portanto a operação é impossível fora dos reais.\n\n");

    // ----------------------- //
    
    // Exercício 14
    printf("14. Digite um número real: ");
	scanf("%f", &f_number[0]);

    if(f_number[0] == 0) printf("14.R O número é igual a 0.\n\n");
    else if(f_number[0] > 0) printf("14.R O número é maior que 0.\n\n");
    else if(f_number[0] < 0) printf("14.R O número é menor que 0.\n\n");

    // ----------------------- //
    
    // Exercício 15
    printf("15. Digite um número inteiro: ");
	scanf("%i", &number[0]);

    if(number[0] % 2 == 0) printf("15.R %i² = %.0f\n\n", number[0], pow(number[0], 2));
    else printf("15.R %i³ = %.0f\n\n", number[0], pow(number[0], 3));

    // ----------------------- //
    
    // Exercício 16
    printf("16. Digite um número inteiro: ");
	scanf("%i", &number[0]);

    if(number[0] == 1 || number[0] == 2) 
    {
        printf("16. Digite os lados do retângulo, separados por espaço: ");
        scanf("%f %f", &f_number[0], &f_number[1]);

        float diagonal = sqrt(pow(f_number[0], 2) + pow(f_number[1], 2));
        float raio = diagonal / 2;
        
        area = M_PI * pow(raio, 2);

        printf("16.R Área do círculo circunscrito: %.2f\n\n", area);
    }
    else if(number[0] == 3 || number[0] == 4 || number[0] == 5) 
    {
        printf("16. Digite o raio do círculo: ");
        scanf("%f", &f_number[0]);

        float lado = f_number[0] * sqrt(2);
        
        area = pow(lado, 2);

        printf("16.R Área do quadrado inscrito: %.2f\n\n", area);
    }
    else
    {
        printf("16. Digite o lado do quadrado: ");
        scanf("%f", &f_number[0]);

        float r_menor, r_maior;

        r_menor = f_number[0] / 2;
        r_maior = f_number[0] / sqrt(2);

        printf("16.R Área da coroa circular: %.2f\n\n", M_PI * (r_menor + r_maior) * (r_maior - r_menor));
    }

    // ----------------------- //
    
    // Exercício 17
    float lado, altura;

    printf("17. Digite um caractere e o raio do círculo, separados por espaço: ");
	scanf(" %c %f", &carac[0], &f_number[0]);

    if(carac[0] == 't' || carac[0] == 'T')
    {
        lado = f_number[0] * sqrt(3);
        altura = lado * (sqrt(3) / 2);
        area = (lado * altura) / 2;

        printf("17.R Área do triângulo inscrito = %.2f\n\n", area);
    }
    else if(carac[0] == 'q' || carac[0] == 'Q')
    {
        lado = f_number[0] * sqrt(2);
        area = pow(lado, 2);

        printf("17.R Área do quadrado inscrito = %.2f\n\n", area);
    }
    else if(carac[0] == 'h' || carac[0] == 'H')
    {
        area = (3 * pow(f_number[0], 2) * sqrt(3)) / 2;

        printf("17.R Área do hexágono inscrito = %.2f\n\n", area);
    }
    else printf("17.R Caractere inválido! Insira os caracteres T, Q ou H.\n\n");

    // ----------------------- //
    
	system("pause");
	return 0;
}