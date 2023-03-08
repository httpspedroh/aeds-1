#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class Ponto
{
    float x, y;
    
    public:

    Ponto(float c_x, float c_y)
    {
        x = c_x;
        y = c_y;
    }

    void setX(float newX) { x = newX; }
    void setY(float newY) { y = newY; }
    float getX() { return x; }
    float getY() { return y; }
    bool equals(Ponto pontoB) { return pontoB.getX() == x && pontoB.getY() == y; }
    double distanciaPara(Ponto pontoB) { return sqrt(pow(pontoB.getX() - x, 2) + pow(pontoB.getY() - y, 2)); }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    Ponto pontofeliz(3, 5);
    Ponto pontotriste(5, 8);

    printf("Ponto feliz: x = %.0f | y = %.0f\n", pontofeliz.getX(), pontofeliz.getY());
    printf("Ponto triste: x = %.0f | y = %.0f\n", pontotriste.getX(), pontotriste.getY());
    printf("\nEles %s iguais.", pontofeliz.equals(pontotriste) ? "são" : "não são");
    printf("\nA distância entre eles é de %.2f\n\n", pontofeliz.distanciaPara(pontotriste));

    // ----------------- // 
	    
	system("pause");
    return 0;
}