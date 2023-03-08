#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <time.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class Utils
{
    public:

    double toCelsius(double fahr)
    {
        if(fahr >= -459.67) return (fahr - 32) * ((double)5 / (double)9);
    }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");
	
    // ----------------- //

    Utils utils;

    double tmpDb;

    printf("> Insira a temperatura em Fahrenheit: ");
    scanf("%lf", &tmpDb);

    printf("%.2lf °F = %.2lf °C\n\n", tmpDb, utils.toCelsius(tmpDb));

    // ----------------- // 
	    
	system("pause");
    return 0;
}