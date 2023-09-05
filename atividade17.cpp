#include <stdio.h>
#include <iostream>
using namespace std;

void resto10(int k){
    if(k>=10)
        k=k%10;
        cout<<"valor de k"<<k;
}

int main(void){
    int A;
    cout<<"digite um valor";
    cin>>A;
    resto10(A);
    cout<<"o novo valor"<<A; 

    return 0;
}