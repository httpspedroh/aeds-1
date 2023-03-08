#include <iostream>
#include <math.h>
#include <string.h>
#include <locale.h>

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------- //

class Item
{
    string nome;
    float preco;

    public:

    Item() {}
    Item(string c_nome, float c_preco)
    { 
        nome = c_nome;
        preco = c_preco;
    }

    void setNome(string newNome) { nome = newNome; }
    void setPreco(float newPreco) { preco = newPreco; }

    string getNome() { return nome; }
    float getPreco() { return preco; }

    virtual void toString() { printf("[Item]\nNome: %s\nPreço: R$%.2f\n\n", getNome().c_str(), getPreco()); }
};

// ------------------------------------------------------------------ //

class Livro: public Item
{
    string autor;

    public:

    Livro(string c_nome, float c_preco, string c_autor)
    { 
        setNome(c_nome);
        setPreco(c_preco);
        setAutor(c_autor);
    }

    void setAutor(string newAutor) { autor = newAutor; }
    string getAutor() { return autor; }

    virtual void toString() { printf("[Livro]\nNome: %s\nPreço: R$%.2f\nAutor: %s\n\n", getNome().c_str(), getPreco(), getAutor().c_str()); }
};

// ------------------------------------------------------------------ //

class CD: public Item
{
    int numFaixas;

    public:

    CD(string c_nome, float c_preco, int c_numFaixas)
    { 
        setNome(c_nome);
        setPreco(c_preco);
        setNumFaixas(c_numFaixas);
    }

    void setNumFaixas(int newNumFaixas) { numFaixas = newNumFaixas; }
    int getNumFaixas() { return numFaixas; }

    virtual void toString() { printf("[CD]\nNome: %s\nPreço: R$%.2f\nNúmero de faixas: %i\n\n", getNome().c_str(), getPreco(), getNumFaixas()); }
};

// ------------------------------------------------------------------ //

class DVD: public Item
{
    int duracao;

    public:

    DVD(string c_nome, float c_preco, int c_duracao)
    { 
        setNome(c_nome);
        setPreco(c_preco);
        setDuracao(c_duracao);
    }

    void setDuracao(int newDuracao) { duracao = newDuracao; }
    int getDuracao() { return duracao; }

    virtual void toString() { printf("[DVD]\nNome: %s\nPreço: R$%.2f\nDuração: %imin\n\n", getNome().c_str(), getPreco(), getDuracao()); }
};

// --------------------------------------------------------------------------------------------------------------------------- //

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // ----------------- //

    Item *itens[3];

    itens[0] = new Livro("Breves respostas para grandes questões", 15.50, "Stephen Hawking");
    itens[1] = new CD("Arrochadeira Top", 5.30, 13);
    itens[2] = new DVD("Cristiano Araújo In The Cities", 29.90, 3);

    for(int x = 0; x != 3; x++) itens[x] -> toString();

    printf("\n");

    // ----------------- // 
	    
	system("pause");
    return 0;
}