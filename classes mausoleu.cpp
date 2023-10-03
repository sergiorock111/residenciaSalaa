#include <iostream>
#include <stdio.h>
using namespace std;
#include <vector>
#include <string>

class Data
{
    int dia, mes, ano;
     string geraString() {
        string dataStr = to_string(dia);
        dataStr.append("/");
        dataStr.append(to_string(mes));
        dataStr.append("/");
        dataStr.append(to_string(ano));
        return dataStr;
    }
    void setDia(int _dia) {
        dia = _dia;
    };
    void setMes(int _mes) {
        mes = _mes;
    };
    void setAno(int _ano) {
        ano = _ano;
    };
};

class paciente
{

private:
    string nome;
    Data dtmorte;

public:
    void set_nome(string _nome)
    {
        nome = _nome;
    }
    void set_dataMorte(Data _dtmorte)
    {
        dtmorte = _dtmorte;
    }

    string get_nome()
    {
        return nome;
    }

    Data get_dtMorte()
    {
        return dtmorte;
    }
};

class mausoleu
{
    string id;
    string localizacao;
    vector<paciente> moradores;

    void set_loc(string _localizacao)
    {
        localizacao = _localizacao;
    }

    void set_id(string _id)
    {
        id = _id;
    }
    string get_id()
    {
        return id;
    }
    string getloc()
    {
        return localizacao;
    }
};

int main()
{





    return 0;
}