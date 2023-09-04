#include <iostream> 
#include <stdio.h> 
using namespace  std;


int main(void){

int temp , c, maiortemp=0;


for(c=0;c<5;c++){

cout<< "digite a temperatura do dia" << endl; 
cin>> temp ;

if (temp>maiortemp){

    maiortemp = temp ;

};


}

cout << "a maior temperatura é " << maiortemp<< endl ;





    return 0;
}