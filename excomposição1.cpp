#include <iostream>
#include <stdio.h>
using namespace std;
#include <vector>
#include <string>

class Estado
{
    string nome;
    string sigla;

public:
    Estado(string Nome, string Sigla)
    {
        nome = Nome;
        sigla = Sigla;
    }
    void setNome(string Nome)
    {
        nome = Nome;
    }
    void setSigla(string Sigla)
    {
        sigla = Sigla;
    }
    string getNome()
    {
        return nome;
    }
    string getSigla()
    {
        return sigla;
    }
};
class Cidade
{
    string nome;
    Estado *estado_da;

public:
    Cidade(Estado e, string Nome)
    {
        estado_da = &e;
        nome = Nome;
    }

    void listadeEstados()
    {
        cout << nome << "cidade: " << estado_da->getNome() << "sigla: " << estado_da->getSigla << endl;
    }
};

int main()
{

    Estado a;
    Cidade b;
    a.setNome("Bahia");
    a.setSigla
}