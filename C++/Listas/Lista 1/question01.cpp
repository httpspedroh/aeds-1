#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class Pessoa
{
    string nome;
    int idade;
    float altura;

    public:

    Pessoa(string c_nome, int c_idade, float c_altura)
    {
        nome = c_nome;
        idade = c_idade;
        altura = c_altura;
    }

    void setNome(string newNome) { nome = newNome; }
    void setIdade(int newIdade) { idade = newIdade; }
    void setAltura(float newAltura) { altura = newAltura; }

    string getNome() { return nome; }
    int getIdade() { return idade; }
    float getAltura() { return altura; }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    string nome;
    int idade;
    float altura;

    printf("> Digite o nome da pessoa: ");
    cin >> nome;

    printf("> Digite a idade da pessoa: ");
    scanf("%i", &idade);

    printf("> Digite a altura da pessoa: ");
    scanf("%f", &altura);

    Pessoa jubileu(nome, idade, altura);

    printf("\nDados inseridos:\n\nNome: ");

    cout << jubileu.getNome();

    printf("\nIdade: %i anos\nAltura: %.2fm\n\n", jubileu.getIdade(), jubileu.getAltura());

    // ----------------- // 
	    
	system("pause");
    return 0;
}