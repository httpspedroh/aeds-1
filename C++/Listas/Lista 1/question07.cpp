#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class Carro
{
    int distancia;
    float combustivel;

    public:

        Carro(int comb = 0, int dist = 0)
        {
            combustivel = comb;
            distancia = dist;
        }

        void abastecer(int litros) { if(combustivel + litros <= 50) combustivel += litros; }
        void mover(int km) 
        { 
            if((km / 15) < combustivel) 
            {
                distancia += km;
                combustivel -= ((float)km / 15);
            }
        }
       
        int getDistancia() { return distancia; }
        float getCombustivel() { return combustivel; }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    Carro chevete(0, 0);
    Carro fusca(0, 0);

    chevete.abastecer(20);
    fusca.abastecer(30);

    chevete.mover(200);
    fusca.mover(400);

    printf("[Chevete]\nDistância percorrida: %i km\nCombustível atual: %.2fL", chevete.getDistancia(), chevete.getCombustivel());
    printf("\n\n[Chevete]\nDistância percorrida: %i km\nCombustível atual: %.2fL\n\n", fusca.getDistancia(), fusca.getCombustivel());

    // ----------------- // 
	    
	system("pause");
    return 0;
}