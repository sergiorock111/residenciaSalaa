#include <iostream>
using namespace std;
int main()
{

int soma , subtracao , multiplicacao , a , b , divisao , resto;
 
 // entradas dos valores 
std::cout << "iremos fazermos operações de soma, subtração, multiplicação, divisão, e resto da divisão ";
std::cout << "digite um numero inteiro";
std::cin >> a;
std::cout << "digite outro numero inteiro";   
std::cin >> b; 

// fazendo os calculos 
soma = a+b;
subtracao = a-b;
multiplicacao = a*b;
divisao = a/b;
resto = a%b;

// retornando os resultados 
std::cout << "a soma = " << soma << std::endl;
std::cout << "a subtração = " << subtracao << std::endl;
std::cout << "a multiplicação = "<< multiplicacao << std::endl;
std::cout << " a divisão = " << divisao << std::endl;
std::cout << "o resto = " << resto << std::endl;

return 0;
}