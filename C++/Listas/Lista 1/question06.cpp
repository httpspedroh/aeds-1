#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class Condicionador
{
    int temperatura, potencia;

    public:

        Condicionador(int temp)
        {
            temperatura = temp;
            potencia = 0;
        }

        void setPotencia(int newPotencia) { if(newPotencia > 0 && newPotencia <= 10) potencia = newPotencia; }
        void setTempExt(int newTemp) { if(newTemp > 0 && newTemp <= 50) temperatura = newTemp; }
        float getTempAtual() { return temperatura - (potencia * 1.8); }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    Condicionador sala(25);
    Condicionador quarto(31);

    sala.setPotencia(5);
    quarto.setPotencia(10);

    printf("> Temperatura da sala: %.1f °C\n> Temperatura do quarto: %.1f °C\n\n", sala.getTempAtual(), quarto.getTempAtual());

    // ----------------- // 
	    
	system("pause");
    return 0;
}