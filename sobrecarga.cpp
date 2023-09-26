#include <iostream>
#include <stdio.h>
using namespace std;
#include <vector>
#include <string>

class Ponto
{
    int x, y;
    public:

     void set_x(int _x){
        x = _x;
    }

    void set_y(int _y){

        y = _y;
    }

    int get_x(){

        return x;
    };

    int get_y(){

        return y;
    }

    bool operator==(Ponto p)
    {
        return p.get_x() == x && p.get_y() == y;
    }

   
    Ponto operator+(Ponto p)
    {

        Ponto p1;
        p1.set_x(p.get_x() + x);
        p1.set_y(p.get_y() + y);
        return p1;
    };
};
int main()
{
Ponto p1;
Ponto p2;

p1.set_x(8);
p1.set_y(8);

p2.set_x(8);
p2.set_y(8);

if(p1==p2){

    cout<<"são iguais"<<endl;
}else
    cout<<"são diferentes"<<endl;

    return 0;
}