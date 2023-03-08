#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class Televisao
{
    int volume, canal;

    public:

        Televisao(int vol, int can)
        {
            volume = vol;
            canal = can;
        }

        void aumentarVolume() { if(volume < 100) volume++; }
        void diminuirVolume() { if(volume > 0) volume--; }
        void aumentarCanal() { if(canal < 50) canal++; }
        void diminuirCanal() { if(canal > 0) canal--; }
        void setCanal(int newCanal) { if(newCanal > 0 && newCanal <= 50) canal = newCanal; }
        void setVolume(int newVolume) { if(newVolume > 0 && newVolume <= 100) volume = newVolume; }

        int getVolume() { return volume; }
        int getCanal() { return canal; }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    Televisao sala(0, 1);

    for(int x = 0; x != 5; x++) sala.aumentarVolume();
    for(int x = 0; x != 10; x++) sala.aumentarCanal();

    printf("> Volume atual: %i/100\n> Canal atual: %i/50\n\n", sala.getVolume(), sala.getCanal());

    sala.setCanal(13);
    sala.setVolume(70);

    printf("> Volume atual: %i/100\n> Canal atual: %i/50\n\n", sala.getVolume(), sala.getCanal());

    // ----------------- // 
	    
	system("pause");
    return 0;
}