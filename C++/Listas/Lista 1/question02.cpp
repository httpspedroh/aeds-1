#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class Elevador
{
    int pessoasTotal = 0, pessoasAtual = 0, andaresTotal = 0, andarAtual = 0;

    public:

    Elevador(int c_pessoas, int c_andares)
    {
        pessoasTotal = c_pessoas;
        andaresTotal = c_andares;
    }

    void entra() { if(pessoasAtual + 1 <= pessoasTotal) pessoasAtual++; }
    void sai() { if(pessoasAtual > 0) pessoasAtual--; }
    void sobe() { if(andarAtual < andaresTotal) andarAtual++; }
    void desce() { if(andarAtual > 0) andarAtual--; }

    int getPessoasAtual() { return pessoasAtual; }
    int getPessoasTotal() { return pessoasTotal; }
    int getAndarAtual() { return andarAtual; }
    int getAndaresTotais() { return andaresTotal; }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    Elevador e_piso1(7, 10);

    printf("> Pessoas no elevador: %i/%i\n", e_piso1.getPessoasAtual(), e_piso1.getPessoasTotal());
    printf("> Andar atual: %i/%i\n\n", e_piso1.getAndarAtual(), e_piso1.getAndaresTotais());

    // ----------------- // 
	    
	system("pause");
    return 0;
}