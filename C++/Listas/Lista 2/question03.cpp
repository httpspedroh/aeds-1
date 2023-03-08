#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <time.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

int random(int interval) { return rand() % interval; }
int minrand(int min, int max) { return random(max - min) + min; }

// --------------------------------------------------------------------------------------------------------------------------- //

class Aluno
{
    string nome;
    int serie, grau;

    public:

    void setNome(string newNome) { nome = newNome; }
    void setSerie(int newSerie) { serie = newSerie; }
    void setGrau(int newGrau) { grau = newGrau; }

    string getNome() { return nome; }
    int getSerie() { return grau; }
    int getGrau() { return serie; }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
	
    // ----------------- //

    string nomes[15] = {"Pedro", "Daniel", "Rick", "Ana", "José", "Fernando", "Heitor", "João", "Bosco", "Yuri", "Erick", "Barbara", "Gustavo", "Larissa", "Bernardo"};
    Aluno alunos[15];

    printf("\n");

    for(int x = 0; x != 15; x++)
    {
        alunos[x].setNome(nomes[x]);
        alunos[x].setSerie(minrand(1, 5));
        alunos[x].setGrau(minrand(1, 3));

        printf("[Aluno %i]\n", x + 1);
        printf("Nome: %s\n", alunos[x].getNome().c_str());
        printf("Série: %i\n", alunos[x].getSerie());
        printf("Grau: %i\n\n", alunos[x].getGrau());
    }

    // ----------------- // 
	    
	system("pause");
    return 0;
}