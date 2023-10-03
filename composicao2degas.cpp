#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;

class Cidade{
    string nome;
    public:
    string getNome() {
        return nome;
    };
    void setNome(string _nome) {
        nome = _nome;
    };
};

class Estado {
    string nome;
    vector<Cidade> cidades;
    public:
    string getNome() {
        return nome;
    };
    void setNome(string _nome) {
        nome = _nome;
    };
    void addCidade(Cidade cidade) {
        cidades.push_back(cidade);
    }
    void listarCidades() {
        cout << "Cidades do estado: " << getNome() << endl;
        for (Cidade c:cidades) {
            cout << c.getNome() << endl;
        }
        cout << endl;
    }
};



int main() {
    Estado e1, e2;   
    e1.setNome("Bahia");
    e2.setNome("Paraiba");
    Cidade c1, c2, c3, c4;
    c1.setNome("Feira de Santana");
    c2.setNome("Campina Grande");
    c3.setNome("Vitoria da Conquista");
    c4.setNome("Patos");
    e1.addCidade(c1);
    e1.addCidade(c3);
    e2.addCidade(c2);
    e2.addCidade(c4);
    e1.listarCidades();
    e2.listarCidades();
    return 0;
}

