#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "CircularLinkedList.h"
using namespace std;



int main(int argc, const char * argv[]) {
    Stack<int> principal;
    Stack<int> res;
    LinkedList<int> listaR;
    
    principal.push(5);
    principal.push(2);
    principal.push(7);
    principal.push(0);
    principal.push(9);
    principal.push(10);
    principal.push(1);
    
    while (!principal.empty())
    {
        int aux = principal.pop()->getInfo();
        res.push(aux);
        
        Stack<int> pilaAux;
        while (!principal.empty()){
            int aux2 = principal.pop()->getInfo();
            if (aux != aux2)
            {
                pilaAux.push(aux2);
            }else{
                listaR.insertFront(aux2);
            }
        }
        principal.clear();
        while (!pilaAux.empty()){
            principal.push(pilaAux.pop()->getInfo());
        }
        
    }
    if(!listaR.empty())
    {
        cout << "Lista R:" << listaR;
    }else{
        cout << "Lista R esta vacía";
    }
    
    return 0;
}
