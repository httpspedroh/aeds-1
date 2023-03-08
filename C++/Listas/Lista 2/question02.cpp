#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class Empregado
{
    string nome, sobrenome;
    float salario;

    public:

    Empregado(string c_nome, string c_sobrenome, float c_salario)
    {
        nome = c_nome;
        sobrenome = c_sobrenome;
        salario = c_salario;
    }

    void setNome(string newNome) { nome = newNome; }
    void setSobrenome(string newSobrenome) { sobrenome = newSobrenome; }
    void setSalario(float newSalario) { salario = newSalario; }

    string getNome() { return nome; }
    string getSobrenome() { return sobrenome; }
    float getSalario() { return salario; }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    Empregado func1("José", "Alencar", 3500.93);
    Empregado func2("Ana", "Maria", 1500.35);

    func1.setNome("Julio");
    func1.setSobrenome("Seixas");
    func1.setSalario(2200.50);

    func2.setNome("Juvenil");
    func2.setSobrenome("Freitas");
    func2.setSalario(4700.35);

    printf("[Funcionário 1]\n\n");
    printf("Nome completo: %s %s\n", func1.getNome().c_str(), func1.getSobrenome().c_str());
    printf("Salário: R$%.2f | Anual: R$%.2f\n", func1.getSalario(), func1.getSalario() * 12);
    printf("Salário com +10%%: R$%.2f | Anual: R$%.2f\n\n", func1.getSalario() * 1.1, (func1.getSalario() * 1.1) * 12);

    printf("[Funcionário 2]\n\n");
    printf("Nome completo: %s %s\n", func2.getNome().c_str(), func2.getSobrenome().c_str());
    printf("Salário: R$%.2f | Anual: R$%.2f\n", func2.getSalario(), func2.getSalario() * 12);
    printf("Salário com +10%%: R$%.2f | Anual: R$%.2f\n\n", func2.getSalario() * 1.1, (func2.getSalario() * 1.1) * 12);

    // ----------------- // 
	    
	system("pause");
    return 0;
}