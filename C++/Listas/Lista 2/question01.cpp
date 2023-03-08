#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class NotaFiscal
{
    string numeroPeca, descricaoPeca;
    int quantidadePeca;
    float precoPeca;

    public:

    string getNumeroPeca() { return numeroPeca; }
    string getDescricaoPeca() { return descricaoPeca; }
    int getQuantidadePeca() { return quantidadePeca; }
    float getPrecoPeca() { return precoPeca; }
    float getTotalNota() { return precoPeca * quantidadePeca; }

    void setNumeroPeca(string newNumero) { numeroPeca = newNumero; }
    void setDescricaoPeca(string newDescricao) { descricaoPeca = newDescricao; }
    void setQuantidadePeca(int newQuantidade) { quantidadePeca = newQuantidade; }
    void setPrecoPeca(float newPreco) { precoPeca = newPreco; }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    string tmpString;
    int tmpInt;
    float tmpFloat;

    NotaFiscal peca1;

    printf("> Insira o n�mero da pe�a: ");
    cin >> tmpString;
    peca1.setNumeroPeca(tmpString);

    printf("> Insira a descri��o da pe�a: ");
    cin >> tmpString;
    peca1.setDescricaoPeca(tmpString);

    printf("> Insira a quantidade da pe�a: ");
    scanf("%i", &tmpInt);
    peca1.setQuantidadePeca(tmpInt);

    printf("> Insira o pre�o da pe�a: ");
    scanf("%f", &tmpFloat);
    peca1.setPrecoPeca(tmpFloat);

    printf("\n----------- Dados da nota fiscal -----------\n\n");
    printf("N�mero da pe�a: %s\n", peca1.getNumeroPeca().c_str());
    printf("Descri��o da pe�a: %s\n", peca1.getDescricaoPeca().c_str());
    printf("Quantidade da pe�a: %i\n", peca1.getQuantidadePeca());
    printf("Pre�o da pe�a: R$%.2f\n\n", peca1.getPrecoPeca());
    printf("TOTAL = R$%.2f\n\n", peca1.getTotalNota());

    // ----------------- // 
	    
	system("pause");
    return 0;
}