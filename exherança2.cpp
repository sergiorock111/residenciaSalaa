#include <iostream>
#include <stdio.h>
using namespace std;
#include <vector>
#include <string>       
#include <math.h>

class Forma
{

public:
    void calcularArea();

};

class Retangulo : Forma
{
    public:
    float calcularArea(float base,float altura){
        cout<<"a área do retangulo é: "<< base*altura << endl;
    }

};

class Circulo : Forma{
    public:
    float calcularArea(float raio , float pi){

        cout<<"a área do circulo é: "<< pi*(pow(raio,2));
    }

};


int main()
{

    Retangulo r ;
    r.calcularArea(20,3);

    Circulo c ;
    c.calcularArea(5,3.14);
    
    return 0;
}