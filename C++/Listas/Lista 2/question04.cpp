#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <time.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class Veiculo
{
    float peso, velMax, preco;

    public:

    Veiculo() {}

    Veiculo(float c_peso, float c_velMax, float c_preco)
    {
        peso = c_peso;
        velMax = c_velMax;
        preco = c_preco;
    }

    void setPeso(float newPeso) { peso = newPeso; }
    void setVelMax(float newVelMax) { velMax = newVelMax; }
    void setPreco(float newPreco) { preco = newPreco; }

    float getPeso() { return peso; }
    float getVelMax() { return velMax; }
    float getPreco() { return preco; }

    void printPeso() { printf("Peso: %.2fkg\n", peso); }
    void printVelMax() { printf("Vel. Máx: %.0fkm/h\n", velMax); }
    void printPreco() { printf("Preço: R$%.2f\n", preco); }
};

// --------------------------------------------------------------------------------------------------------------------------- //

class Motor
{
    int numCilindros, potencia;

    public:

    Motor() {}

    Motor(int c_numCilindros, int c_potencia)
    {
        numCilindros = c_numCilindros;
        potencia = c_potencia;
    }

    void setNumCilindros(int newNumCilindros) { numCilindros = newNumCilindros; }
    void setPotencia(int newPotencia) { potencia = newPotencia; }

    int getNumCilindros() { return numCilindros; }
    int getPotencia() { return potencia; }

    void printNumCilindros() { printf("Número de cilindros: %i\n", numCilindros); }
    void printPotencia() { printf("Potência: %i cavalos", potencia); }
};

// --------------------------------------------------------------------------------------------------------------------------- //

class CarroPasseio: public Veiculo, public Motor 
{
    string modelo, cor;

    public: 

    CarroPasseio(string c_modelo, string c_cor)
    {
        modelo = c_modelo;
        cor = c_cor;

        Veiculo v_dados(0, 0, 0);
        Motor v_motor(0, 0);
    }

    void setModelo(string newModelo) { modelo = newModelo; }
    void setCor(string newCor) { cor = newCor; }

    string getModelo() { return modelo; }
    string getCor() { return cor; }

    void printDados() 
    {
        printf("Modelo: %s (%s)\n", getModelo().c_str(), getCor().c_str());
        
        printPeso();
        printVelMax();
        printPreco();
        printNumCilindros();
        printPotencia();

        printf("\n\n");
    }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");
	
    // ----------------- //

    CarroPasseio unin("Uno", "Laranja");

    unin.setPeso(1500.5);
    unin.setVelMax(200);
    unin.setPreco(150000);
    unin.setNumCilindros(6);
    unin.setPotencia(300);
    unin.printDados();

    // ----------------- // 
	    
	system("pause");
    return 0;
}