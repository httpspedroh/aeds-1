#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class Aluno
{
    string nome;
    int matricula, horaExtra;
    float nota;
    bool bolsista;

    public:

    Aluno() {};

    Aluno(string c_nome, int c_matricula, int c_horaextra, float c_nota, bool c_bolsista)
    {
        setNome(c_nome);
        setMatricula(c_matricula);
        setHoraExtra(c_horaextra);
        setNota(c_nota);
        setBolsista(c_bolsista);
    }

    void setNome(string newNome) { nome = newNome; }
    void setMatricula(int newMatricula) { matricula = newMatricula; }
    void setHoraExtra(int newHoraExtra) { horaExtra = newHoraExtra; }
    void setNota(float newNota) { nota = newNota; }
    void setBolsista(bool newBolsista) { bolsista = newBolsista; }
    void lancaHoras(int qtd_horas) { horaExtra += qtd_horas; }

    string getNome() { return nome; }
    int getMatricula() { return matricula; }
    int getHoraExtra() { return horaExtra; }
    float getNota() { return nota; }
    bool getBolsista() { return bolsista; }
};

// ---------------------------------------------------------------------------------------------------------------------- //

class Turma
{
    string nome;
    int qtdAlunos;
    Aluno alunos[10];
    
    public:

    Turma(string c_nome)
    {
        setNome(c_nome);
        
        qtdAlunos = 0;
    }

    void setNome(string newNome) { nome = newNome; }

    string getNome() { return nome; }
    int getQtdAlunos() { return qtdAlunos; }

    void mostraAlunos() 
    { 

        printf("-----------------------------------------------------\n[Todos os alunos]\n\n");

        for(int x = 0; x != qtdAlunos; x++) 
        {
            printf("[Aluno %i]\n", x + 1);
            printf("Nome: %s [Matrícula #%i]\n", alunos[x].getNome().c_str(), alunos[x].getMatricula());
            printf("Horas extras: %ih\n", alunos[x].getHoraExtra());
            printf("Nota: %.1f\n", alunos[x].getNota());
            printf("Bolsista: %s\n\n", alunos[x].getBolsista() ? "Sim" : "Não");
        }
    };

    void mostraAlunosAbaixoDaMedia() // Média = 6.0
    {
        printf("-----------------------------------------------------\n[Alunos abaixo da média]\n\n");

        for(int x = 0; x != qtdAlunos; x++) 
        {
            if(alunos[x].getNota() < 6.0)
            {
                printf("Nome: %s [Matrícula #%i]\n", alunos[x].getNome().c_str(), alunos[x].getMatricula());
                printf("Nota: %.1f\n\n", alunos[x].getNota());
            }
        }
    };

    void mostraAlunosBolsistas() 
    {
        printf("-----------------------------------------------------\n[Alunos bolsistas]\n\n");

        for(int x = 0; x != qtdAlunos; x++) 
        {
            if(alunos[x].getBolsista() == true)
            {
                printf("Nome: %s [Matrícula #%i]\n", alunos[x].getNome().c_str(), alunos[x].getMatricula());
            }
        }

        printf("\n");
    };

    void inserirAluno(Aluno newAluno)
    { 
        alunos[getQtdAlunos()] = newAluno; 
        qtdAlunos++;
    }
};

// ---------------------------------------------------------------------------------------------------------------------- //

class Testa
{
    public:
    
    void main()
    {
        Turma terceirao("3002");

        terceirao.inserirAluno({"Pedro", 1, 0, 10, true});
        terceirao.inserirAluno({"Vivian", 2, 3, 9.5, false});
        terceirao.inserirAluno({"Luana", 3, 2, 6.5, true});
        terceirao.inserirAluno({"Gabrielly", 4, 3, 4, false});
        terceirao.inserirAluno({"Marcelo", 5, 0, 0, true});
        terceirao.inserirAluno({"Carlos", 6, 10, 7, true});
        terceirao.inserirAluno({"Clara", 7, 6, 2, true});
        terceirao.inserirAluno({"Maria", 8, 10, 10, true});
        terceirao.inserirAluno({"Heitor", 9, 0, 1, false});
        terceirao.inserirAluno({"Vanessa", 10, 5, 10, true});
        
        terceirao.mostraAlunos();
        terceirao.mostraAlunosAbaixoDaMedia();
        terceirao.mostraAlunosBolsistas();
    }
};

// ---------------------------------------------------------------------------------------------------------------------- //

int main() 
{
    setlocale(LC_ALL, "Portuguese");

	// ----------------- // 
	
    Testa teste1;

    teste1.main();

    // ----------------- // 
	    
	system("pause");

    return 0;
}