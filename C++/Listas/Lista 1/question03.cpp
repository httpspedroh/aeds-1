#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class Relogio
{
    int horas = 0, minutos = 0, segundos = 0;

    public:

    Relogio(int c_horas, int c_minutos, int c_segundos)
    {
        horas = c_horas;
        minutos = c_minutos;
        segundos = c_segundos;
    }

    void setHora(int s_horas, int s_minutos, int s_segundos)
    {
        horas = s_horas;
        minutos = s_minutos;
        segundos = s_segundos;
    }

    void getHora(int *r_horas, int *r_minutos, int *r_segundos)
    {
        *r_horas = horas;
        *r_minutos = minutos;
        *r_segundos = segundos;
    }

    void segundosPp() {
        segundos++;
        
        if(segundos == 60) 
        {
            minutos++;
            segundos = 0;

            if(minutos == 60) 
            {
                horas++;
                minutos = 0;

                if(horas == 24) horas = 0;
            }
        }
    }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    Relogio pc(0, 0, 0);

    int h, m, s;

    pc.getHora(&h, &m, &s);

    printf("> Hora atual: %02i:%02i:%02i\n", h, m, s);

    pc.setHora(19, 21, 35);
    pc.getHora(&h, &m, &s);

    printf("> Hora setada: %02i:%02i:%02i\n", h, m, s);

    pc.segundosPp();
    pc.getHora(&h, &m, &s);

    printf("> Hora segundos++: %02i:%02i:%02i\n\n", h, m, s);

    // ----------------- // 
	    
	system("pause");
    return 0;
}