#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class ContaCorrente
{
    float saldo;

    public:

    ContaCorrente() {}
    ContaCorrente(float c_saldo) { saldo = c_saldo; }

    float getSaldo() { return saldo; }
    void setSaldo(float newSaldo) { saldo = newSaldo; }
    void depositar(float valor) { saldo += valor; }

    virtual void sacar(float valor) 
    { 
        float total = valor + (valor * 0.05);

        if(getSaldo() >= total) setSaldo(getSaldo() - total);
    }
};

// ------------------------------------------------------------------ //

class ContaEspecial: public ContaCorrente
{
    public:

    ContaEspecial(float c_saldo) { setSaldo(c_saldo); }

    virtual void sacar(float valor) 
    { 
        float total = valor + (valor * 0.01);

        if(getSaldo() >= total) setSaldo(getSaldo() - total);
    }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    ContaCorrente *contas[2];

    contas[0] = new ContaCorrente(3000);
    contas[0] -> depositar(2000);
    contas[0] -> sacar(4000);

    contas[1] = new ContaEspecial(10000);
    contas[1] -> depositar(5000);
    contas[1] -> sacar(8000);

    for(int x = 0; x != 2; x++) printf("> Saldo final (Conta %i) = R$%.2f\n", x + 1, contas[x] -> getSaldo());

    printf("\n");

    // ----------------- // 
	    
	system("pause");
    return 0;
}