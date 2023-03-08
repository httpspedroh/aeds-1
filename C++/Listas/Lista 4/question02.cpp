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

    while(1)
    {
        try
        {
            float sf;

            printf("> Digite um número inteiro: ");
            scanf("%f", &sf);

            if(sf != (int)sf) throw invalid_argument("O número inserido não é inteiro!");
            else return printf("O número inserido é inteiro.\n");
        }
        catch(invalid_argument x) 
        {
            printf("%s\n\n", x.what());
        }
    }
    

    // ----------------- // 
	    
	system("pause");
    return 0;
}