#include <stdio.h>
#include <locale.h>
#include <tgmath.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

int arredonda(float valor)
{
	int valorint = valor;
	float partedec = valor - valorint;

	if(partedec >= 0.5) valorint++;
	else valorint--;
	return valorint;
}

double logta(double numero, double base)
{
	for(int x = 0; x != numero; x++)
	{
		if(pow(base, x) == numero) return x;
	}
	return -1;
}

int fatorial(int number)
{
	int total = number;

	for(int x = 1; x != number; x++)
	{
		total *= number - x;
	}
	return total;
}

int isPar(int number) 
{
	return number % 2 == 0 ? 1 : 0;
}

float volumeEsf(float raio)
{
	return (4 * M_PI * pow(raio, 3)) / (float)3;
}

void resultadoAluno(int nota1, int nota2, int nota3)
{
	int total = nota1 + nota2 + nota3;

	if(total < 40) printf("Total: %i | Aluno reprovado\n\n", total);
	else if(total > 40 && total < 60) printf("Total: %i | Aluno em exame especial\n\n", total);
	else if(total >= 60) printf("Total: %i | Aluno aprovado\n\n", total);
}

bool isPrimo(int number)
{
	bool result = true;

	if(number < 2) result = false;
	if(number != 2 && number % 2 == 0) result = false;
	if(!(number % 1 == 0 && number % number == 0)) result = false;

	if(result == true)
	{
		for(int n = 2; n <= number / 2; n++)
		{
			if(number % n == 0) 
			{
				result = false;
				break;
			}
		}
	}
	return result;
}

void getDayName(int dia, int mes, int ano)
{
	int diaSemana = ((1461 * (ano + 4800 + (mes - 14) / 12)) / 4 + (367 * (mes - 2 - 12 * ((mes - 14) / 12))) / 12 - (3 * ( (ano + 4900 + (mes - 14) / 12) / 100)) / 4 + dia - 32075) % 7;

	switch(diaSemana)
	{
		case 0: printf("%02i/%02i/%04i = Segunda-feira\n\n", dia, mes, ano); break;
		case 1: printf("%02i/%02i/%04i = Terça-feira\n\n", dia, mes, ano); break;
		case 2: printf("%02i/%02i/%04i = Quarta-feira\n\n", dia, mes, ano); break;
		case 3: printf("%02i/%02i/%04i = Quinta-feira\n\n", dia, mes, ano); break;
		case 4: printf("%02i/%02i/%04i = Sexta-feira\n\n", dia, mes, ano); break;
		case 5: printf("%02i/%02i/%04i = Sábado\n\n", dia, mes, ano); break;
		case 6: printf("%02i/%02i/%04i = Domingo\n\n", dia, mes, ano); break;
	}
}

void enesimoCapeta(int n)
{
	n -= 1;

	int numerador = pow(2, n);
	int denominador_pot = pow(3, n);

	printf("%i/3 * 5^%i\n\n", numerador, denominador_pot);
}

int multiplicaSenhor(int n, int vezes)
{
	int soma = 0;

	if(vezes > 0)
	{
		soma = n + multiplicaSenhor(n, vezes - 1);
	}
	return soma;
}

void printTriangulo(int altura)
{
	printf("\n");

	for(int x = 0; x != altura; x++)
	{
		for(int espH = 0; espH != altura - (x + 1); espH++)
		{
			printf(" ");
		}

		for(int y = (x * 2) + 1; y != 0; y--)
		{
			if(y % 2 != 0) printf("x");
			else printf("o");
		}

		printf("\n");
	}

	printf("\n");
}

int random(int interval)
{
	return rand() % interval;
}

int minrand(int min, int max)
{
	return random(max - min) + min;
}

#define QTD_ALUNOS 5

int dadosAluno[QTD_ALUNOS][2];

void recebeDados()
{
	for(int x = 0; x != QTD_ALUNOS; x++)
	{
		do
		{
			printf("> Insira a idade do aluno %i: ", x + 1);
			scanf("%i", &dadosAluno[x][0]);
		}
		while(dadosAluno[x][0] <= 0);
		
		do
		{
			printf("> Insira a altura em cm do aluno %i: ", x + 1);
			scanf("%i", &dadosAluno[x][1]);
		}
		while(dadosAluno[x][1] <= 0);

		printf("\n");
	}
}

int mediaIdade()
{
	int total = 0;
	for(int x = 0; x != QTD_ALUNOS; x++) total += dadosAluno[x][0];
	return total / QTD_ALUNOS;
}

int mediaAltura()
{
	int total = 0;
	for(int x = 0; x != QTD_ALUNOS; x++) total += dadosAluno[x][1];
	return total / QTD_ALUNOS;
}

void idadeAcimaMedia()
{
	int total = 0;
	for(int x = 0; x != QTD_ALUNOS; x++) total += dadosAluno[x][0];

	int media = total / QTD_ALUNOS;

	printf("> ALUNOS COM IDADE ACIMA DA MÉDIA:\n\n");

	for(int x = 0; x != QTD_ALUNOS; x++)
	{
		if(dadosAluno[x][0] > media) printf("Aluno %i\n", x + 1);
	}

	printf("\n");
}

int countCapitalChars(char string[], int x)
{
	int count = 0;
	
	if(string[x] == '\0') return count;
	else
	{
		if(string[x] >= 'A' && string[x] <= 'Z') count++;
		return count += countCapitalChars(string, ++x);
	}
}

void invertString(char string[], int x)
{
	int len = strlen(string);
	char old_c = string[x];

	string[x] = string[len - x - 1];
	string[len - x - 1] = old_c;

	if(x != len / 2) return invertString(string, ++x);
}

bool isPalindromo(char string[], int x)
{
	int len = strlen(string);

	if(string[x] == '\0') return true;
	else if(string[x] != string[len - x - 1]) return false;
	else return isPalindromo(string, ++x);
}

bool isSpecial(char carac)
{
	if((carac >= 48 && carac <= 57) && (carac >= 65 && carac <= 90) || (carac >= 97 && carac <= 122)) return false;
	else return true;
}

char firstSpecial(char string[], int x)
{
	if(string[x] == '\0') return 'n';
	else
	{
		if(isSpecial(string[x])) return string[x];
		else return firstSpecial(string, ++x);
	}
}

// ---------------------------------------------------------------------------------------------------------------------- //

int main() {

	srand(time(NULL));

	setlocale(LC_ALL, "Portuguese");

	// --------------------------- //
	
	int n=1;

	for(int x = 1; x <= 5; x++) 
	{
    	for(int j = 1; j <= x; j++) 
		{
			n++;
		}
	}

	printf("%i\n\n", n);

	// --------------------------- //

	/*int escolhido = 0;
	
	do
	{
		printf("Insira um número de 1 a 10: ");
		scanf("%i", &escolhido);
	} 
	while(escolhido > 10 || escolhido < 1);
	
	printf("\n");

	srand(time(NULL));

	int achou = 0;

	for(int x = 0; ; x++)
	{
		int number = (rand() % 10) + 1;

		if(number == escolhido)
		{
			printf("Rodada %i | Número sorteado: %i | SORTEADO!\n\n", x + 1, number);
			break;
		}
		else printf("Rodada %i | Número sorteado: %i\n", x + 1, number);
	}*/
	
	// ----------------- //

	/*int baseValue;
	float basePercentage;

	printf("Digite o valor desejado: ");
	scanf("%i", &baseValue);

	printf("Digite a porcentagem desejada: ");
	scanf("%f", &basePercentage);

	printf("\n%.2f%% de %i é igual a %.2f\n\n", basePercentage, baseValue, (baseValue * basePercentage) / 100);*/

	// ----------------- //

	/*float productValue, productDiscount;
	short int productAmount;

	printf("Insira o valor do produto (Exemplo: 4,50): ");
	scanf("%f", &productValue);

	printf("Insira a quantidade do produto (Exemplo: 7): ");
	scanf("%i", &productAmount);

	printf("Insira a porcentagem de desconto (Exemplo: 50): ");
	scanf("%f", &productDiscount);

	printf("\nCom %.2f%% de desconto, você pagará o total de R$%.2f em %i unidades do produto. (Total antigo: R$%.2f)\n\n", productDiscount, (productValue * productAmount) * (productDiscount / 100), productAmount, (productValue * productAmount));*/

	// ----------------- //

	/*short int userChilds;
	int userCandys;

	printf("Insira a quantidade de filhos que você tem (Exemplo: 4): ");
	scanf("%i", &userChilds);

	printf("Insira a quantidade de doces que você tem (Exemplo: 35): ");
	scanf("%i", &userCandys);

	printf("\nCada filho seu receberá %i bala%s, e lhe restará %i no bolso.\n\n", userCandys / userChilds, userChilds == 1 ? ("") : ("s"), userCandys % userChilds);*/

	// ----------------- //

	/*float productPrice; 
	short int productInstallments; 
	char productName[100];

	printf("Insira o nome do produto (Exemplo: Computador): ");
	scanf("%[^\n]%*c", productName);

	printf("Insira o preço do produto (Exemplo: 1650,90): ");
	scanf("%f", &productPrice);

	printf("Insira em quantas vezes você deseja parcelar (Exemplo: 12): ");
	scanf("%i", &productInstallments);

	printf("\nVocê pagará o produto \"%s\" em %ix de R$%.2f.\n\n", productName, productInstallments, productPrice / productInstallments);*/

	// ----------------- //

	/*float tireValue, tireAmount, tireShippingValue, totalValue;

	printf("Insira o valor do pneu (Exemplo: 450,90): ");
	scanf("%f", &tireValue);

	printf("Insira a quantidade desejada (Exemplo: 4): ");
	scanf("%f", &tireAmount);

	printf("Insira o valor do frete (Exemplo: 15,90): ");
	scanf("%f", &tireShippingValue);

	totalValue = (tireValue * tireAmount) * 0.95 + (tireShippingValue * tireAmount);

	printf("\nValor para pagamento à vista: R$%.2f + R$%.2f de frete\t(TOTAL: R$%.2f)", (tireValue * tireAmount) * 0.95, tireShippingValue * tireAmount, totalValue);
	
	totalValue = (tireValue * tireAmount) + (tireShippingValue * tireAmount);

	printf("\nValor para pagamento à prazo: R$%.2f + R$%.2f de frete\t(TOTAL: R$%.2f)\n\t2x de %.2f\n\t3x de %.2f\n\n", tireValue * tireAmount, tireShippingValue * tireAmount, totalValue, totalValue / 2, totalValue / 3);*/

	// ----------------- //

	/*float valorTotal, valorInserido, troco, resto;

	printf("Insira o valor total da compra: ");
	scanf("%f", &valorTotal);

	printf("Insira o valor inserido: ");
	scanf("%f", &valorInserido);

	resto = troco = valorInserido - valorTotal;

	int notas200 = resto / 200;
	resto -= (200 * notas200);

	int notas100 = resto / 100;
	resto -= (100 * notas100);

	int notas50 = resto / 50;
	resto -= (50 * notas50);

	int notas20 = resto / 20;
	resto -= (20 * notas20);

	int notas10 = resto / 10;
	resto -= (10 * notas10);

	int notas5 = resto / 5;
	resto -= (5 * notas5);

	int notas2 = resto / 2;
	resto -= (2 * notas2);

	// --------------- //

	resto = round(resto * 100);

	int moedas1 = resto / 100;
	resto -= (100 * moedas1);

	int moedas50 = resto / 50;
	resto -= (50 * moedas50);

	int moedas25 = resto / 25;
	resto -= (25 * moedas25);

	int moedas10 = resto / 10;
	resto -= (10 * moedas10);

	int moedas5 = resto / 5;
	resto -= (5 * moedas5);

	int moedas1c = resto / 1;
	resto -= (1 * moedas1c);

	printf("\nSeu troco será de R$%.2f, dividido em:\n\nNotas de R$200: %i\nNotas de R$100: %i\nNotas de R$50: %i\nNotas de R$20: %i\nNotas de R$10: %i\nNotas de R$5: %i\nNotas de R$2: %i\n\n", troco, notas200, notas100, notas50, notas20, notas10, notas5, notas2);
	printf("Moedas de R$1: %i\nMoedas de R$0,50: %i\nMoedas de R$0,25: %i\nMoedas de R$0,10: %i\nMoedas de R$0,05: %i\nMoedas de R$0,01: %i\n\n", moedas1, moedas50, moedas25, moedas10, moedas5, moedas1c);*/

	// ----------------- // 
	
	/*float notas[2], media;
	char conceito;

	printf("Insira sua primeira nota: ");
	scanf("%f", &notas[0]);
          
	printf("Insira sua segunda nota: ");
	scanf("%f", &notas[1]);
    
	media = (notas[0] + notas[1]) / 2;

	conceito = (media < 4.0) ? 'E' : (media >= 4.0 && media <= 6.0) ? 'D' : (media >= 6.0 && media <= 7.5) ? 'C' : (media >= 7.5 && media <= 9.0) ? 'B' : 'A';

	printf("\nA média das suas notas é de %.1f e você está com conceito \"%c\"\n\n", media, conceito);*/

	// ----------------- // 

	/*int mes;

	printf("Insira um número inteiro entre 1 e 12: ");
	scanf("%i", &mes);

	switch(mes)
	{
		case 1: printf("\nMês: Janeiro\n\n"); break;
		case 2: printf("\nMês: Fevereiro\n\n"); break;
		case 3: printf("\nMês: Março\n\n"); break;
		case 4: printf("\nMês: Abril\n\n"); break;
		case 5: printf("\nMês: Maio\n\n"); break;
		case 6: printf("\nMês: Junho\n\n"); break;
		case 7: printf("\nMês: Julho\n\n"); break;
		case 8: printf("\nMês: Agosto\n\n"); break;
		case 9: printf("\nMês: Setembro\n\n"); break;
		case 10: printf("\nMês: Outubro\n\n"); break;
		case 11: printf("\nMês: Novembro\n\n"); break;
		case 12: printf("\nMês: Dezembro\n\n"); break;
		default: printf("\nx Número inválido!"); break;
	}*/

	// ----------------- // 

	/*char carac;

	printf("Insira um caractere: ");
	scanf("%c", &carac);

	switch(carac)
	{
		case '.': printf("\nÉ um ponto\n\n"); break;
		case ',': printf("\nÉ uma vírgula\n\n"); break;
		case ';': printf("\nÉ um ponto e vírgula\n\n"); break;
		default: printf("\nNão é nenhum\n\n"); break;
	}*/

	// ----------------- // 

	/*float salario, emprestimo, maxparcela; 
	int parcelas; 

	printf("Digite o valor do seu salário: "); 
	scanf("%f", &salario);  

	printf("Digite o valor do empréstimo desejado: "); 
	scanf("%f", &emprestimo); 

	printf("Digite o número de parcelas que deseja pagar: "); 
	scanf("%i", &parcelas); 

	maxparcela = salario * 0.3; 

	if((emprestimo / parcelas) <= maxparcela) printf("\nParabéns! Valor do empréstimo autorizado: R$%.2f em %ix de R$%.2f\n\n", emprestimo, parcelas, emprestimo / parcelas); 
	else if((emprestimo / parcelas) >= maxparcela) printf("\nO valor do empréstimo foi negado. O valor máximo para emprestimo é de R$%.2f, com parcelas de R$%.2f\n\n", maxparcela * parcelas, maxparcela);*/
  
	// ----------------- //

	/*while(num < 10)
	{
		printf("Num: %i\n", num++);
	}*/

	// ------------ //
	
	/*printf("Insira um número inteiro positivo: ");
	scanf("%i", &num);

	int impar = 1;

	while(num > 0)
	{
		printf("Ímpar: %i\n", impar);

		impar += 2;
		num--;
	}

	// ------------ //

	printf("Insira um número inteiro positivo: ");
	scanf("%i", &num);
	
	int x = 1, rodou;

	while(num > 0)
	{
		printf("%i\n", x);

		rodou++;

		if(rodou % 2 == 0) x += 7;
		else x += 4;
		
		num--;
  	}*/

	// ------------ //

	/*int aluno = 0, max_alunos = 5, notamax = 0, c_menormedia = 0, c_conceitoa = 0;
	float n_aluno, mediaturma;

	printf("Insira a nota máxima da prova: ");
	scanf("%i", &notamax);

	while(aluno < 20)
	{
		printf("Insira a nota do aluno %i: ", aluno + 1);
		scanf("%f", &n_aluno);

		mediaturma += n_aluno;

		if(n_aluno < (0.6 * notamax)) c_menormedia++;
		else if(n_aluno > (0.9 * notamax)) c_conceitoa++;

		aluno++;
	}

	mediaturma /= (float)max_alunos;

	printf("\nMédia da turma: %.2f\n", mediaturma);
	printf("Alunos com menos de 60%%: %i\n", c_menormedia);
	printf("Alunos com mais de 90%%: %i\n\n", c_conceitoa);*/
	
	// ----------------- // 
	
	/*int total = 0, primeiro, segundo;

	printf("Insira os números separados por espaço: ");
	scanf("%i %i", &primeiro, &segundo);

	for(; segundo > 0; segundo--) total += primeiro;

	printf("\nResultado: %i\n\n", total);*/

	// ----------------- // 
	
	/*int velocidade;

	do {
		printf("Insira a velocidade máxima do creu: ");
		scanf("%i", &velocidade);
	}
	while(velocidade < 1);

	for(int i = 1; i <= velocidade; i++) 
	{
		printf("\nVelocidade %i do creu: ", i);
	}*/

	// ----------------- // 
	
	/*int original;

	do 
	{
		printf("Insira um número inteiro maior que 0: ");
		scanf("%i", &original);
	}
	while(original <= 0);

	for(int linhas = original; linhas > 0; linhas--)
	{
		for(int colunas = original; colunas > 0; colunas--)
		{
			if(linhas % 2 == 0) printf("%s", colunas % 2 == 0 ? "x " : "o ");
			else printf("%s", colunas % 2 == 0 ? "o " : "x ");
		}

		printf("\n");
	}*/

	// ----------------- // 
	
	/*int number, result = 1;

	printf("Insira um número para verificação: ");
	scanf("%i", &number);

	if(number < 2) result = 0;
	if(number != 2 && number % 2 == 0) result = 0;
	if(!(number % 1 == 0 && number % number == 0)) result = 0;

	if(result == 1)
	{
		for(int n = 2; n <= number / 2; n++)
		{
			if(number % n == 0) 
			{
				result = 0;
				break;
			}
		}
	}

	printf("O número %i %s primo\n\n", number, result == 1 ? "é" : "não é");*/

	// ----------------- // 
	
	/*int continuar, quantidade;
	float total, valor;

	do
	{
		printf("\nDigite o valor do produto: ");
		scanf("%f", &valor);

		printf("Digite a quantidade do produto: ");
		scanf("%i", &quantidade);

		total += (valor * quantidade);

		char condicao;

		printf("Há mais algum produto? (S ou N)");
		scanf(" %c", &condicao);
 
		if(condicao == 's' || condicao ==  'S') continuar = 1;
		else if(condicao == 'n' || condicao ==  'N') continuar = 0;
	}
	while(continuar == 1);

	printf("\nTotal: R$%.2f\n\n", total);*/

	// ----------------- //
	
	
	// ----------------- // 
	    
	system("pause");

	// ----------------- // 
	
	return(0);
}