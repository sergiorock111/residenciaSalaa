
#include <iostream> 
#include <stdio.h> 
using namespace  std;


int main(void){

int a,c ,cont=0;
cout << "digite um numero inteiro ";
cin >> a; 

for (c=1;c<=a;c++) {

    if (a%c==0){
        cout << c << endl ;
        cont++ ;
    }
    
};
 if(cont==2){
cout << "o total é "<<cont <<endl;
}
return 0;
}


