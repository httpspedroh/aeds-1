#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main() 
{
    setlocale(LC_ALL, "Portuguese");

    int varint[] = {0, 0, 0};
    float varfloat[] = {0.0};

    // ----------------------- //
    
    // Exercício 1
    printf("1. Insira a quantidade de números inteiros a serem lidos: ");
    scanf("%i", &varint[0]);

    while(varint[0] > 0)
    {
        printf("1. Insira o %iº número inteiro: ", varint[0]);
        scanf("%i", &varint[1]);

        varint[2] += varint[1];
        varint[0]--;
    }

    printf("1.R: Soma dos números inteiros: %i\n\n", varint[2]);
  
    // ----------------------- //

    // Exercício 2
    printf("2. Insira a quantidade L de elementos da sequência de Fibonacci: ");
    scanf("%i", &varint[0]);

    double anterior = 0, atual = 1;

    if(varint[0] >= 2) printf("2.R: 0 1");
    else if(varint[0] == 1) printf("2.R: 0");

    for(int x = 0; x != varint[0] - 2; x++)
    {
        double old_atual = atual;

        atual += anterior;
        anterior = old_atual;

        printf(" %.0f", atual);
    }

    printf("\n\n");

    // ----------------------- //
    
    // Exercício 3
    printf("3. Insira um número inteiro L: ");
    scanf("%i", &varint[0]);

    int anterior = 0, atual = 1;

    if(atual < varint[0]) printf("3.R: 0 1");

    while(varint[0] > 0)
    {
        int old_atual = atual;

        atual = anterior + atual;
        anterior = old_atual;

        if(atual < varint[0]) printf(" %i", atual);
        else break;
    }

    printf("\n\n");

    // ----------------------- //

    // Exercício 4
    int first_termo, razao, termo_n;

    printf("4. Insira o primeiro termo da PG: ");
    scanf("%i", &first_termo);

    printf("4. Insira a razão da PG: ");
    scanf("%i", &razao);

    printf("4. Insira o termo N a ser calculado: ");
    scanf("%i", &termo_n);

    // Algoritmo pedido
    int result_1 = first_termo * round(pow(razao, termo_n - 1));

    // -------------- //

    // Algoritmo sem exponenciação
    int imp_pow = razao;

    for(int temp_count = termo_n - 1; temp_count > 1; temp_count--) imp_pow *= razao;

    int result_2 = first_termo * imp_pow;

    // -------------- //

    // Algoritmo sem exponenciação e sem multiplicação
    int atual = razao, total_pow = 0, result_3 = 0;

    if(termo_n > 1)
    {
        for(int x = 1; x != termo_n - 1; x++) // Exponenciação
        {
            int interno = 0;

            for(int y = 0; y != razao; y++) // Multiplicação
            {
                interno += atual;
            }

            atual = interno;
        }

        total_pow = atual;
    }

    for(int x = 1; x <= first_termo; x++) result_3 += total_pow;

    if(razao == 1 || termo_n == 1) result_1 = first_termo, result_2 = first_termo, result_3 = first_termo;

    printf("\n4.R: Resultado do algoritmo 1 = %i\n4.R: Resultado do algoritmo 2 = %i\n4.R: Resultado do algoritmo 3 = %i\n\n", result_1, result_2, result_3);

    // ----------------------- //
    
    // Exercício 5
    printf("5. Insira a quantidade de múltiplos desejados: ");
    scanf("%i", &varint[0]);

    printf("5.R: ");

    for(int i = 0; varint[0] > 0; i++)
    {
        if(i % 5 == 0)
        {
            printf("%i ", i);
            varint[0]--;
        }
    }

    printf("\n\n");

    // ----------------------- //
    
    // Exercício 6
    printf("6. Insira o termo N da sequência de Fibonacci: ");
    scanf("%i", &varint[0]);

    double anterior = 0, atual = 1;

    for(int x = 2; x < varint[0]; x++)
    {
        double old_atual = atual;

        atual += anterior;
        anterior = old_atual;

        if(x == varint[0] - 1) printf("6.R: %iº termo de Fibonacci: %.0f", varint[0], atual);
    }

    printf("\n\n");

    // ----------------------- //
    
    // Exercício 7
    do
    {
        printf("7. Digite a quantidade de alunos: ");
        scanf("%i", &varint[0]);
    }
    while(varint[0] < 1);

    do
    {
        printf("7. Digite a quantidade de provas: ");
        scanf("%i", &varint[1]);
    }
    while(varint[1] < 1);

    int c_mais80 = 0;
    float total_turma = 0;

    printf("\n");

    for(int x = 0; x != varint[0]; x++) // Loop de alunos
    {
        float total_aluno = 0;

        for(int y = 0; y != varint[1]; y++) // Loop de provas
        {
            float nota_prova;

            do 
            {
                printf("7. [Aluno: %i | Prova: %i] Digite a nota: ", x + 1, y + 1);
                scanf("%f", &nota_prova);
            }
            while(nota_prova < 0 || nota_prova > 10);

            total_aluno += nota_prova;
            total_turma += nota_prova;
        }

        printf("7. >>> Média do aluno %i: %.2f\n\n", x + 1, total_aluno / (float)varint[1]);

        if((total_aluno / varint[1]) >= 8.0) c_mais80++;
    }

    printf("7. MÉDIA DA TURMA: %.2f\n", total_turma / (float)(varint[0] * varint[1]));
    printf("7. %.2f%% DA TURMA FICOU COM 80%% OU MAIS DE MÉDIA.\n\n", (float)((c_mais80 * 100) / varint[0]));

    // ----------------------- //
    
    // Exercício 8
    printf("8. Insira um número inteiro I: ");
    scanf("%i", &varint[0]);

    printf("8. Insira um número real R: ");
    scanf("%f", &varfloat[0]);

    printf("\n");

    while(varint[0] > 10)
    {
        printf("I: %i\n", varint[0]);

        varint[0] -= 2;
    }

    printf("\n");

    while(varfloat[0] < 10)
    {
        printf("R: %.2f, I: %i\n", varfloat[0], varint[0]);
        
        varfloat[0] ++;
    }

    printf("\n");

    // ----------------------- //
    
    // Exercício 9
    printf("9. Insira a quantidade N de elementos a mostrar: ");
    scanf("%i", &varint[0]);

    int inicial = 1;

    printf("9.R: ");

    for(int x = 0; x != varint[0]; x++)
    {
        printf("%i ", inicial);

        inicial += 2;
    }

    printf("\n\n");

    // ----------------------- //
    
    // Exercício 10
    printf("10. Insira a quantidade N de elementos a mostrar: ");
    scanf("%i", &varint[0]);

    int inicial = 1;

    printf("10.R: ");

    while(varint[0] > 0)
    {
        if((inicial % 3 == 0 && inicial % 5 == 0) || inicial % 7 == 0)
        {
            printf("%i ", inicial);

            varint[0]--;
        }

        inicial += 2;
    }

    printf("\n\n");

    // ----------------------- //
    
    // Exercício 11
    printf("11. Insira a quantidade N de elementos a mostrar: ");
    scanf("%i", &varint[0]);

    printf("11. Insira o valor 'a': ");
    scanf("%i", &varint[1]);

    printf("11. Insira o valor 'b': ");
    scanf("%i", &varint[2]);

    int inicial = 1;

    printf("11.R: ");

    while(varint[0] > 0)
    {
        if((inicial % 3 == 0 && inicial % 5 == 0) || inicial % 7 == 0)
        {
            if(inicial > varint[1] && inicial < varint[2]) printf("%i ", inicial);
        }

        varint[0]--;
        inicial += 2;
    }

    printf("\n\n");

    // ----------------------- //
    
    // Exercício 12
    char caractere;

    printf("12. Insira o caractere desejado: ");
    scanf(" %c", &caractere);

    if(caractere >= 65 && caractere <= 90) printf("12.R: Caractere maiúsculo\n\n");
    else if(caractere >= 97 && caractere <= 122) printf("12.R: Caractere minúsculo\n\n");
    else if(caractere >= 48 && caractere <= 57) printf("12.R: Dígito\n\n");
    else printf("12.R: Outro caractere\n\n");

    // ----------------------- //

	system("pause");
    return 0;
} 