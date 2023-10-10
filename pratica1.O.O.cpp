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

class Cliente : public Usuario
{
    string habilitacao;
    public:
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

void PersistenciaCliente( Cliente cliente){

    ofstream SalveCliente;
    SalveCliente.open("Cliente.txt",ios_base::app);
    if(SalveCliente.is_open())
    {
        SalveCliente << cliente.getHabilitacao()<<endl;
        SalveCliente << cliente.getNome()<<endl;
        SalveCliente << cliente.getCpf()<<endl;
        SalveCliente << cliente.getEndereco()<<endl;
        SalveCliente << cliente.getTelefone()<<endl;

        SalveCliente << " " << endl;
        SalveCliente.close();
    }
    else
    {
        cout<< "erro ao abrir o arquivo "<< endl;
    }
}

class Funcionario : public Usuario
{
    vector<Funcionario> HistoricoAlugueisFuncionario;

    void AluguelVeiculo()
    {
    }
    void FinalizarAlugueis()
    {
    }
};
void PersistenciaFuncionario( Funcionario funcionario){

    ofstream SalveFuncionario;
    SalveFuncionario.open("Funcionario.txt",ios_base::app);
    if(SalveFuncionario.is_open())
    {
        SalveFuncionario << funcionario.getNome()<<endl;
        SalveFuncionario << funcionario.getCpf()<<endl;
        SalveFuncionario << funcionario.getEndereco()<<endl;
        SalveFuncionario << funcionario.getTelefone()<<endl;
        SalveFuncionario << " " << endl;
        SalveFuncionario.close();
    }
    else
    {
        cout<< "erro ao abrir o arquivo "<< endl;
    }
}

class Veiculo{
    string identificador,marca,modelo;
    int anoFabricacao;
    float precoPorDia;

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
        cout << "digite 1 para adicionar Usuario" << endl;
        cout << "digite 2 para listar Usuario" << endl;
        cout << "digite 3 para alterar Usuario" << endl;
        cout << "digite 4 para deletar Usuario" << endl;
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

vector<Cliente> VetCliente;
void MenuCliente()

{
    int escolha;
    Cliente cliente;

    string cpf, nome, endereco, telefone, buscarcpf, habilitacao;
    
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
    system("clear");
        cout << "digite sua habilitaçao: " << endl;
        getline(cin, habilitacao);
        cliente.setHabilitacao(habilitacao);
        cout << "digite seu nome: " << endl;
        getline(cin, nome);
        cliente.setNome(nome);
        cout << "digite seu cpf: " << endl;
        getline(cin, cpf);
        cliente.setCpf(cpf);
        cout << "digite seu endereço: " << endl;
        getline(cin, endereco);
        cliente.setEndereco(endereco);
        cout << "digite seu telefone: " << endl;
        getline(cin, telefone);
        cliente.setTelefone(telefone);
        
        VetCliente.push_back(cliente);

        PersistenciaUsuario(cliente);

        break;
    case 2:
    system("clear");
    for (auto &user : VetCliente)
        {
            cout << "Dados do Cliente:" << endl
                 << endl;
            cout << "Habilitação: " << user.getCpf()<< endl;
            cout << "cpf: " << user.getCpf()<< endl;
            cout << "nome: " << user.getNome()<< endl;
            cout << "endereço: " << user.getEndereco()<< endl;
            cout << "Telefone: " << user.getTelefone()<< endl;
        };

        break;
    case 3:

        system("clear");
        int valor;
        cout << "digite seu cpf" << endl;
        getline(cin, buscarcpf);
        for (auto it = VetCliente.begin(); it != VetCliente.end(); it++)
        {
            if (buscarcpf == it->getCpf())
            {
                cout << endl;
                cout << endl;
                cout << " o cliente é " << endl;

                cout << " Habilitação: " << it->getHabilitacao() << endl;
                cout << " nome: " << it->getNome() << endl;
                cout << " cpf: " << it->getCpf() << endl;
                cout << " endereco: " << it->getEndereco() << endl;
                cout << " telefone: " << it->getTelefone() << endl;

                cout << endl;
                cout << endl;
                char novohabilitacao;
                char novonome;
                char novocpf;
                char novoendereco;
                char novotelefone;

                cout << "Deseja alterar a habilitação? (S/N) " << endl;
                cin >> novohabilitacao;
                cin.ignore();
                if (novohabilitacao == 'S' || novohabilitacao == 's')
                {
                    cout << "novo nome: " << endl;
                    getline(cin, nome);
                    cliente.setNome(nome);
                }

                cout << "Deseja alterar o nome? (S/N) " << endl;
                cin >> novonome;
                cin.ignore();
                if (novonome == 'S' || novonome == 's')
                {
                    cout << "novo nome: " << endl;
                    getline(cin, nome);
                    cliente.setNome(nome);
                }
                cout << "Deseja alterar seu cpf? (S/N) " << endl;
                cin >> novocpf;
                cin.ignore();
                if (novocpf == 'S' || novocpf == 's')
                {
                    cout << "novo cpf :" << endl;
                    getline(cin, cpf);
                    cliente.setCpf(cpf);
                };

                cout << "Deseja alterar seu endereço ? (S/N) " << endl;
                cin >> novoendereco;
                cin.ignore();
                if (novoendereco == 'S' || novoendereco == 's')
                {
                    cout << "nova endereco: " << endl;
                    getline(cin, endereco);
                    cliente.setEndereco(endereco);
                };

                cout << "Deseja alterar seu telefone ? (S/N) " << endl;
                cin >> novotelefone;
                cin.ignore();
                if (novotelefone == 'S' || novotelefone == 's')
                {
                    cout << "nova telefone: " << endl;
                    getline(cin, telefone);
                    cliente.setTelefone(endereco);
                };

                cout << "dados alterados com sucesso " << endl;
            }
        }
        break;
    case 4:
            system("clear");
            buscarcpf = "";
        int cont = -1;
        cout << "digite seu cpf para excluir" << endl;
        getline(cin, buscarcpf);

        vector<Cliente>::iterator i;
        i = VetCliente.begin();

        for (auto it = VetCliente.begin(); it != VetCliente.end(); it++)
        {
            cont += 1;
            if (buscarcpf == it->getCpf())
            {
                advance(i, cont);
                VetCliente.erase(i);
                cout << " Cliente excluido com sucesso " << endl;
            }
        }
    break;
    };
};


vector<Funcionario> VetFuncionario;
void MenuFuncionario()
{
    int escolha;
    Funcionario funcionario;

    string cpf, nome, endereco, telefone, buscarcpf;
    
    do
    {
        cout << "Escolha uma Opção do Menu Abaixo:" << endl;
        cout << "digite 1 para adicionar Funcionario" << endl;
        cout << "digite 2 para listar Funcionario" << endl;
        cout << "digite 3 para alterar Funcionario" << endl;
        cout << "digite 4 para deletar Funcionario" << endl;
        cout << "digite 0 para voltar ao Menu Principal:" << endl;
        cin >> escolha;
        cin.ignore();
    } while (escolha < 0 || escolha > 5);

    switch (escolha)
    {
    case 1:
    system("clear");
        
        cout << "digite seu nome: " << endl;
        getline(cin, nome);
        funcionario.setNome(nome);
        cout << "digite seu cpf: " << endl;
        getline(cin, cpf);
        funcionario.setCpf(cpf);
        cout << "digite seu endereço: " << endl;
        getline(cin, endereco);
        funcionario.setEndereco(endereco);
        cout << "digite seu telefone: " << endl;
        getline(cin, telefone);
        funcionario.setTelefone(telefone);
        
        VetFuncionario.push_back(funcionario);

        PersistenciaUsuario(funcionario);

        break;
    case 2:
    system("clear");
    for (auto &user : VetFuncionario)
        {
            cout << "Dados do Funcionario:" << endl
                 << endl;
            cout << "cpf: " << user.getCpf()<< endl;
            cout << "nome: " << user.getNome()<< endl;
            cout << "endereço: " << user.getEndereco()<< endl;
            cout << "Telefone: " << user.getTelefone()<< endl;
        };

        break;
    case 3:

        system("clear");
        int valor;
        cout << "digite seu cpf" << endl;
        getline(cin, buscarcpf);
        for (auto it = VetFuncionario.begin(); it != VetFuncionario.end(); it++)
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
                    funcionario.setNome(nome);
                }
                cout << "Deseja alterar seu cpf? (S/N) " << endl;
                cin >> novocpf;
                cin.ignore();
                if (novocpf == 'S' || novocpf == 's')
                {
                    cout << "novo cpf :" << endl;
                    getline(cin, cpf);
                    funcionario.setCpf(cpf);
                };

                cout << "Deseja alterar seu endereço ? (S/N) " << endl;
                cin >> novoendereco;
                cin.ignore();
                if (novoendereco == 'S' || novoendereco == 's')
                {
                    cout << "nova endereco: " << endl;
                    getline(cin, endereco);
                    funcionario.setEndereco(endereco);
                };

                cout << "Deseja alterar seu telefone ? (S/N) " << endl;
                cin >> novotelefone;
                cin.ignore();
                if (novotelefone == 'S' || novotelefone == 's')
                {
                    cout << "nova telefone: " << endl;
                    getline(cin, telefone);
                    funcionario.setTelefone(endereco);
                };

                cout << "dados alterados com sucesso " << endl;
            }
        }
        break;
    case 4:
            system("clear");
            buscarcpf = "";
        int cont = -1;
        cout << "digite seu cpf para excluir" << endl;
        getline(cin, buscarcpf);

        vector<Funcionario>::iterator i;
        i = VetFuncionario.begin();

        for (auto it = VetFuncionario.begin(); it != VetFuncionario.end(); it++)
        {
            cont += 1;
            if (buscarcpf == it->getCpf())
            {
                advance(i, cont);
                VetFuncionario.erase(i);
                cout << " Funcionario excluido com sucesso " << endl;
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
        case 2: 
            MenuCliente();
            break;
        case 3: 
            MenuFuncionario();
            break;
        default:
            break;
        }

    } while ( opcao != 0);

    return 0;
}