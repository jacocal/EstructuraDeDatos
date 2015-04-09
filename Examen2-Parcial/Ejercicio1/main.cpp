#include <iostream>
#include "Stack.h"
#include "LinkedList.h"
#include "Node.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    int numero = 4;
    Stack<int> binario;
    
    if(numero == 0)
    {
        binario.push(0);
        cout << binario;
    }else{
    while(numero >= 1)
    {
        int x = numero % 2;
        binario.push(x);
        numero = (numero - x) / 2;
    }
        cout << binario;
    }
    
    return 0;
}
