#include <iostream>
#include <stdio.h>
using namespace std;
#include <vector>
#include <string>       

class Animal
{

    int idade;

public:
    void fazerSom();

    int recebeValores(){
        cout <<"DIGITE SUA IDADE"<<endl;
        cin>>idade;
        return idade;
    };

};

class Cachorro : Animal
{   public:
    void fazerSom(){
        cout<< "au au"<<endl;

    }
    void MostraValores(){
        recebeValores();
        fazerSom();
    }
};

int main()
{
    Cachorro a ;
    a.MostraValores();
    
    return 0;
}