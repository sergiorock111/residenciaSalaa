#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Usuario
{
private:
    string cpf, nome, endereco, telefone;

public:
    void setCpf(string _cpf)
    {
        cpf = _cpf;
    }
    string getCpf()
    {
        return cpf;
    }
    void setNome(string _nome)
    {
        nome = _nome;
    }
    string getNome()
    {
        return nome;
    }
    void setEndereco(string _endereco)
    {
        endereco = _endereco;
    }
    string getEndereco()
    {
        return endereco;
    }
    void setTelefone(string _telefone)
    {
        telefone = _telefone;
    }
    string getTelefone()
    {
        return telefone;
    }
};

void PersistenciaUsuario( Usuario User){

    ofstream SalveUser;
    SalveUser.open("usuarios.txt",ios_base::app);
    if(SalveUser.is_open())
    {
        SalveUser << User.getCpf()<<endl;
        SalveUser << User.getNome()<<endl;
        SalveUser << User.getEndereco()<<endl;
        SalveUser << User.getTelefone()<<endl;
        SalveUser << " " << endl;
        SalveUser.close();
    }
    else
    {
        cout<< "erro ao abrir o arquivo "<< endl;
    }
}

class Cliente : Usuario
{
    string habilitacao;
    vector<Cliente> HistoricoAlugueis;
    void setHabilitacao(string _habilitacao)
    {
        habilitacao = _habilitacao;
    }
    string getHabilitacao()
    {
        return habilitacao;
    }

    void CotarAluguel()
    {
    }

    void SolicitarAluguel()
    {
    }

    void DevolverAluguel()
    {
    }
};

class Funcionario : Usuario
{
    vector<Funcionario> HistoricoAlugueisFuncionario;

    void AluguelVeiculo()
    {
    }
    void FinalizarAlugueis()
    {
    }
};

int MenuGeral()
{
    int escolha;
    do
    {
        cout << "Escolha uma Opção do Menu Abaixo:" << endl;
        cout << "digite 1 para gerenciar Usuario" << endl;
        cout << "digite 2 para gerenciar Cliente" << endl;
        cout << "digite 3 para gerenciar Funcionario" << endl;
        cin >> escolha;
        cin.ignore();
    } while (escolha < 1 || escolha > 3);
    return escolha;
};

vector<Usuario> VetUsuario;
void MenuUsuario()
{
    int escolha;
    Usuario usuario;

    string cpf, nome, endereco, telefone, buscarcpf;
    
    do
    {
        cout << "Escolha uma Opção do Menu Abaixo:" << endl;
        cout << "digite 1 para adicionar Cliente" << endl;
        cout << "digite 2 para listar Cliente" << endl;
        cout << "digite 3 para alterar Cliente" << endl;
        cout << "digite 4 para deletar Cliente" << endl;
        cout << "digite 0 para voltar ao Menu Principal:" << endl;
        cin >> escolha;
        cin.ignore();
    } while (escolha < 0 || escolha > 5);

    switch (escolha)
    {
    case 1:
        cout << "digite seu cpf: " << endl;
        getline(cin, cpf);
        usuario.setCpf(cpf);
        cout << "digite seu nome: " << endl;
        getline(cin, nome);
        usuario.setNome(nome);
        cout << "digite seu endereço: " << endl;
        getline(cin, endereco);
        usuario.setEndereco(endereco);
        cout << "digite seu telefone: " << endl;
        getline(cin, telefone);
        usuario.setTelefone(telefone);
        
        VetUsuario.push_back(usuario);

        PersistenciaUsuario(usuario);
        break;
    case 2:
        for (auto &user : VetUsuario)
        {
            cout << "Dados do Cliente:" << endl
                 << endl;
            cout << "cpf: " << user.getCpf()<< endl;
            cout << "nome: " << user.getNome()<< endl;
            cout << "endereço: " << user.getEndereco()<< endl;
            cout << "Telefone: " << user.getTelefone()<< endl;
        };
        break;

    case 3:

        int valor;
        cout << "digite seu cpf" << endl;
        getline(cin, buscarcpf);
        for (auto it = VetUsuario.begin(); it != VetUsuario.end(); it++)
        {
            if (buscarcpf == it->getCpf())
            {
                cout << endl;
                cout << endl;
                cout << " o cliente é " << endl;

                cout << " nome: " << it->getNome() << endl;
                cout << " cpf: " << it->getCpf() << endl;
                cout << " endereco: " << it->getEndereco() << endl;
                cout << " telefone: " << it->getTelefone() << endl;

                cout << endl;
                cout << endl;
                char novonome;
                char novocpf;
                char novoendereco;
                char novotelefone;
                cout << "Deseja alterar o nome? (S/N) " << endl;
                cin >> novonome;
                cin.ignore();
                if (novonome == 'S' || novonome == 's')
                {
                    cout << "novo nome: " << endl;
                    getline(cin, nome);
                    usuario.setNome(nome);
                }
                cout << "Deseja alterar seu cpf? (S/N) " << endl;
                cin >> novocpf;
                cin.ignore();
                if (novocpf == 'S' || novocpf == 's')
                {
                    cout << "novo cpf :" << endl;
                    getline(cin, cpf);
                    usuario.setCpf(cpf);
                };

                cout << "Deseja alterar seu endereço ? (S/N) " << endl;
                cin >> novoendereco;
                cin.ignore();
                if (novoendereco == 'S' || novoendereco == 's')
                {
                    cout << "nova endereco: " << endl;
                    getline(cin, endereco);
                    usuario.setEndereco(endereco);
                };

                cout << "Deseja alterar seu telefone ? (S/N) " << endl;
                cin >> novotelefone;
                cin.ignore();
                if (novotelefone == 'S' || novotelefone == 's')
                {
                    cout << "nova telefone: " << endl;
                    getline(cin, telefone);
                    usuario.setTelefone(endereco);
                };

                cout << "dados alterados com sucesso " << endl;
            }
        }
    case 4:

        buscarcpf = "";
        int cont = -1;
        cout << "digite seu cpf para excluir" << endl;
        getline(cin, buscarcpf);

        vector<Usuario>::iterator i;
        i = VetUsuario.begin();

        for (auto it = VetUsuario.begin(); it != VetUsuario.end(); it++)
        {
            cont += 1;
            if (buscarcpf == it->getCpf())
            {
                advance(i, cont);
                VetUsuario.erase(i);
                cout << " Usuario excluido com sucesso " << endl;
            }
        }
        break;
        
    };
};

int main()
{
    int opcao;
    Usuario usuario;

    Cliente cliente;
    Funcionario funcionario;

    do
    {
        opcao = MenuGeral();
        switch (opcao)
        {
        case 1:
            MenuUsuario();
            break;
        default:
            break;
        }

    } while ( opcao != 0);

    return 0;
}