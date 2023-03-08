#include <iostream>
#include <math.h>
#include <locale.h>
#include <stdexcept>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    double ponto[3];

    try
    {
        printf("> Digite o valor do ponto A: ");
        scanf("%lf", &ponto[0]);
        
        printf("> Digite o valor do ponto B: ");
        scanf("%lf", &ponto[1]);

        printf("> Digite o valor do ponto C: ");
        scanf("%lf", &ponto[2]);

        if(ponto[0] + ponto[1] <= ponto[2] || ponto[0] + ponto[2] <= ponto[1] || ponto[1] + ponto[2] <= ponto[0]) throw invalid_argument("Os pontos informados não podem formar um triângulo!");
        else return printf("\n> Área do triângulo = %.2lf\n", (ponto[0] * ponto[2]) / (double)2);
    }
    catch(invalid_argument x)
    {
        printf("\n%s\n\n", x.what());
    }

    // ----------------- // 
	    
	system("pause");
    return 0;
}