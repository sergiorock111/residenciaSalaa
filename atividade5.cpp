#include <iostream> 
#include <stdio.h> 
using namespace  std;


int main(void){

float s=0,c=0,media, nota;


while (c<10){
    cout<< "digite sua média";
    cin>> nota;

    s=s+nota;
    c++;
    cout<< "digite sua média";
    cin>> nota;


    media=s/c;
    cout << "a sua média é "<< media<< endl ;
}




return 0;
}
