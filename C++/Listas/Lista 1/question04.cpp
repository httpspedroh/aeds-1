#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class Circulo
{
    float raio, c_x, c_y;

    private:

        float getArea() { return M_PI * pow(raio, 2); }
        float getX() { return c_x; }
        float getY() { return c_y; }
        float distanciaEntreDois(Circulo circ2) { 
            return sqrt(pow(getX() - circ2.getX(), 2) + pow(getY() - circ2.getY(), 2)); 
        }
        float getCircunferencia() { return 2 * M_PI * raio; }

    public:

        Circulo(float c_raio) { 
            raio = c_raio; 
            c_x = 0.0;
            c_y = 0.0;
        }

        void setRaio(float s_raio) { raio = s_raio; }
        void increaseRaio(float s_percent) { raio += (raio * s_percent) / 100; }
        void setCentro(float x, float y) {
            c_x = x;
            c_y = y;
        }

        void printRaio() { printf("Raio do círculo = %.2f\n", raio); }
        void printCentro() { printf("Centro do círculo = (%.0f, %.0f)\n", c_x, c_y); }
        void printArea() { printf("Área do círculo = %.2f\n", getArea()); }
        void printCircunferencia() { printf("Circunferência do círculo = %.2f\n", getCircunferencia()); }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    Circulo redondo(5);

    redondo.setRaio(10);
    redondo.increaseRaio(10);
    redondo.setCentro(3, 5);

    redondo.printRaio();
    redondo.printCentro();
    redondo.printArea();
    redondo.printCircunferencia();

    printf("\n");

    // ----------------- // 
	    
	system("pause");
    return 0;
}