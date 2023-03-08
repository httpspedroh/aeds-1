#include <iostream>
#include <math.h>
#include <locale.h>
#include <stdexcept>

using namespace std;

class NumberFormatException: public exception
{
    public:

    string errorMsg() { return "Você deve inserir números inteiros!"; }
};

class ArrayIndexOutOfBoundsException: public exception
{
    public:

    string errorMsg() { return "O index inserido está fora da array!"; }
};

bool isNumber(const string& s)
{
    for(char const &ch : s) 
    {
        if(std::isdigit(ch) == 0) return false;
    }
    return true;
}

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    int vetor[10];

    for(int i = 0; i != 10; i++)
    {
        string inserir, posicao;

        while(1)
        {
            try
            {
                printf("> Digite um número inteiro para inserir: ");
                cin >> inserir;

                if(!isNumber(inserir)) throw NumberFormatException();
                else break;
            }
            catch(NumberFormatException x)
            {
                printf("%s\n\n", x.errorMsg().c_str());
            }
        }

        while(1)
        {
            try
            {
                printf("> Digite a posição a inserir: ");
                cin >> posicao;

                printf("\n");

                int i_posicao;

                if(!isNumber(posicao)) throw ArrayIndexOutOfBoundsException();
                else
                {
                    i_posicao = stoi(posicao);

                    if(i_posicao < 0 || i_posicao > 9) throw ArrayIndexOutOfBoundsException();
                    else
                    {
                        vetor[i_posicao] = stoi(inserir);
                        break;
                    }
                }
            }
            catch(ArrayIndexOutOfBoundsException x)
            { 
                printf("%s\n\n", x.errorMsg().c_str());
            }
        }
    }

    for(int x = 0; x != 10; x++) printf("vetor[%i] = %i\n", x, vetor[x]);

    printf("\n");
    
    // ----------------- // 
	    
	system("pause");
    return 0;
}