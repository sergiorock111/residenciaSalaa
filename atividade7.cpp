#include <iostream> 
#include <stdio.h> 
using namespace  std;


int main(void){

int a , acum=0, c;

cout << "digite um numero inteiro ";
cin >> a; 

for (c=0;c<=a;c++) {

    acum = acum+c;

};
 
 cout << "a soma dos numero menores é: " << acum << endl ;





return 0;
}