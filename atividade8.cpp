#include <iostream> 
#include <stdio.h> 
using namespace  std;


int main(void){

int a , acum=1, c;

cout << "digite um numero inteiro ";
cin >> a; 

for (c=1;c<=a;c++) {

    acum = acum*c;

};
 
 cout << "o fatorial é " << acum << endl ;





return 0;
}