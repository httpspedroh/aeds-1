#include <iostream>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class Elevador
{
    int pessoas_Total, pessoas_Atual, andares_Total, andares_Atual;

    public:

    Elevador(int c_pessoas, int c_andares) {
        pessoas_Total = c_pessoas;
        pessoas_Atual = 0;
        andares_Total = c_andares;
        andares_Atual = 0;
    }

    void entra() { if(pessoas_Atual + 1 <= pessoas_Total) pessoas_Atual++; }
    void sai() { if(pessoas_Atual > 0) pessoas_Atual--; }
    void sobe() { if(andares_Atual < andares_Total) andares_Atual++; }
    void desce() { if(andares_Atual > 0) andares_Atual--; }

    int getPessoasAtual() { return pessoas_Atual; }
    int getPessoasTotal() { return pessoas_Total; }
    int getAndarAtual() { return andares_Atual; }
    int getAndaresTotais() { return andares_Total; }
    
    void setPessoasAtual(int pessoas) { pessoas_Atual = pessoas; }
    void setPessoasTotal(int pessoas) { pessoas_Total = pessoas; }
    void setAndarAtual(int andar) { andares_Atual = andar; }
    void setAndaresTotal(int andares) { andares_Total = andares; }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    Elevador e_teste(10, 17);

    printf("> Pessoas no elevador: %i/%i\n", e_teste.getPessoasAtual(), e_teste.getPessoasTotal());
    printf("> Andar atual: %i/%i\n\n", e_teste.getAndarAtual(), e_teste.getAndaresTotais());

    // Testando a classe
    for(int i = 0; i != 3; i++) e_teste.sobe();

    e_teste.desce();

    for(int i = 0; i != 5; i++) e_teste.entra();
    for(int i = 0; i != 2; i++) e_teste.sai();

    printf("> Pessoas no elevador: %i/%i\n", e_teste.getPessoasAtual(), e_teste.getPessoasTotal());
    printf("> Andar atual: %i/%i\n\n", e_teste.getAndarAtual(), e_teste.getAndaresTotais());
    return 0;
}