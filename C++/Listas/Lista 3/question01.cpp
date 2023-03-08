#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class Funcionario
{
    string nome;
    float salario;

    public:

    Funcionario() {}

    Funcionario(string c_nome, float c_salario)
    {
        setNome(c_nome);
        setSalario(c_salario);
    }

    void setNome(string newNome) { nome = newNome; }
    void setSalario(float newSalario) { salario = newSalario; }
    string getNome() { return nome; }
    float getSalario() { return salario; }

    virtual void exibeDados() { printf("[Funcionário]\nNome: %s\nSalário: R$%.2f\n\n", getNome().c_str(), getSalario()); }
};

// ------------------------------------------------------------------ //

class Gerente: public Funcionario
{
    public:

    Gerente(string c_nome, float c_salario) 
    { 
        setNome(c_nome);
        setSalario(c_salario);
    }

    virtual void exibeDados() { printf("[Gerente]\nNome: %s\nSalário: R$%.2f\n\n", getNome().c_str(), getSalario()); }
};

// ------------------------------------------------------------------ //

class AssistTec: public Funcionario
{
    int matricula;
    float aumento;

    public:

    AssistTec(string c_nome, float c_salario, int c_matricula, float c_aumento) 
    { 
        setNome(c_nome);
        setSalario(c_salario);
        setMatricula(c_matricula);
        setAumento(c_aumento);
    }

    void setMatricula(int newMatricula) { matricula = newMatricula; }
    int getMatricula() { return matricula; }
    void setAumento(float newAumento) { aumento = newAumento; }
    float getAumento() { return aumento; }

    virtual void exibeDados() 
    { 
        printf("[Assistente Técnico]\nNome: %s\nMatrícula: %i\nSalário: R$%.2f (+%.0f%%)\n\n", getNome().c_str(), getMatricula(), getSalario() * (1 + (aumento / 100)), aumento); 
    }
};

// ------------------------------------------------------------------ //

class AssistADM: public Funcionario
{
    // 0 = Dia | 1 = Noite

    int matricula, turno;
    float adicional;

    public:

    AssistADM(string c_nome, float c_salario, int c_matricula, int c_turno) 
    { 
        setNome(c_nome);
        setSalario(c_salario);
        setMatricula(c_matricula);
        setTurno(c_turno);

        if(c_turno == 0) adicional = 0;
        else adicional = 20;
    }

    void setMatricula(int newMatricula) { matricula = newMatricula; }
    int getMatricula() { return matricula; }
    void setTurno(int newTurno) { turno = newTurno; }
    int getTurno() { return turno; }
    void setAdicional(float newAdicional) { adicional = newAdicional; }
    float getAdicional() { return adicional; }

    virtual void exibeDados() 
    {
        float result = 0;

        if(getTurno() == 1) result =  getSalario() * (1 + (adicional / 100));
        else result = getSalario();

        printf("[Assistente ADM]\nNome: %s\nMatrícula: %i\nTurno: %s (+%.0f%% de adicional)\nSalário: R$%.2f\n\n", getNome().c_str(), getMatricula(), getTurno() == 0 ? "Dia" : "Noite", getAdicional(), result); 
    }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    Funcionario *funcs[5];

    funcs[0] = new Funcionario("Maria", 3000);
    funcs[1] = new Gerente("Carlos", 10000);
    funcs[2] = new AssistTec("Julio", 5000, 13, 10);
    funcs[3] = new AssistADM("Amanda", 7000, 20, 0);
    funcs[4] = new AssistADM("Laura", 8000, 25, 1);

    for(int x = 0; x != 5; x++) funcs[x] -> exibeDados();

    // ----------------- // 
	    
	system("pause");
    return 0;
}