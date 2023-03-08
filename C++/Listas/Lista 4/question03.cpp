#include <iostream>
#include <math.h>
#include <locale.h>
#include <stdexcept>

using namespace std;

class ExcecaoAcimaDeCem: public exception 
{ 
    public:

    string errorMsg() { return "A soma chegou a 100!"; }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    float soma = 0;
    int total = 0;

    while(1)
    {
        try
        {
            float sf;

            printf("> Digite um número para somar: ");
            scanf("%f", &sf);

            soma += sf;
            total++;

            printf("> Soma atual: %.1f\n> Total de números somados: %i\n> Média: %.1f\n\n", soma, total, soma / total);

            if(soma > 100) throw ExcecaoAcimaDeCem();
        }
        catch(ExcecaoAcimaDeCem x)
        {
            printf("%s\n", x.errorMsg().c_str());
            return false;
        }
    }
    

    // ----------------- // 
	    
	system("pause");
    return 0;
}