#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class Veiculo
{
    string nome;

    public:

    Veiculo() {}
    Veiculo(string c_nome) { setNome(c_nome); }

    void setNome(string newNome) { nome = newNome; }
    string getNome() { return nome; }

    virtual void listarVerificacoes() { printf("> Verificações para %s: Ajustes, limpeza, etc\n", getNome().c_str()); }
    virtual void ajustar() { printf("> O veículo %s foi ajustado com sucesso.\n", getNome().c_str()); }
    virtual void limpar() { printf("> O veículo %s foi limpo com sucesso.\n", getNome().c_str()); }
};

// ------------------------------------------------------------------ //

class Bicicleta: public Veiculo
{
    public:

    Bicicleta(string c_nome) { setNome(c_nome); }

    virtual void listarVerificacoes() { printf("> Verificações em %s: Conferir pneus, pedais e banco\n", getNome().c_str()); }
    virtual void ajustar() { printf("> A bicicleta %s foi ajustada com sucesso.\n", getNome().c_str()); }
    virtual void limpar() { printf("> A bicicleta %s foi limpa com sucesso.\n", getNome().c_str()); }
};

// ------------------------------------------------------------------ //

class Automovel: public Veiculo
{
    float nivelOleo;

    public:

    Automovel(string c_nome) 
    { 
        setNome(c_nome); 
        setNivelOleo(0);
    }

    float getNivelOleo() { return nivelOleo; }
    virtual void setNivelOleo(float newNivel) { nivelOleo = newNivel; }

    virtual void listarVerificacoes() { printf("> Verificações em %s: Conferir pneus, portas, motor, óleo\n", getNome().c_str()); }
    virtual void ajustar() { printf("> O automóvel %s foi ajustado com sucesso.\n", getNome().c_str()); }
    virtual void limpar() { printf("> O automóvel %s foi limpo com sucesso.\n", getNome().c_str()); }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    Bicicleta bike("BMX");
    Automovel land("Land Rover");

    bike.listarVerificacoes();
    bike.ajustar();
    bike.limpar();

    printf("\n");

    land.listarVerificacoes();
    land.ajustar();
    land.limpar();
    land.setNivelOleo(100.0);

    printf("\n");

    // ----------------- // 
	    
	system("pause");
    return 0;
}