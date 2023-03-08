#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class Animal
{
    public:

    Animal() {}

    virtual void fala() { printf("Fala genérica\n"); }
};

// ------------------------------------------------------------------ //

class Homem: public Animal
{
    public:

    virtual void fala() { printf("Oi\n"); }
};

// ------------------------------------------------------------------ //

class Cao: public Animal
{
    public:

    virtual void fala() { printf("Au au\n"); }
};

// ------------------------------------------------------------------ //

class Gato: public Animal
{
    public:

    virtual void fala() { printf("Miau\n"); }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    Animal *zoo[10];

    zoo[0] = new Animal();

    for(int x = 1; x != 4; x++) zoo[x] = new Homem();
    for(int x = 4; x != 7; x++) zoo[x] = new Cao();
    for(int x = 7; x != 10; x++) zoo[x] = new Gato();

    for(int x = 0; x != 10; x++) zoo[x] -> fala();

    printf("\n");

    // ----------------- // 
	    
	system("pause");
    return 0;
}