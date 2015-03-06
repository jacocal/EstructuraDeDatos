#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;



int main (){
    
    LinkedList<int> * numeros = new LinkedList<int>();
    
    cout << "primer valor: ";
    int primerValor;
    cin >> primerValor;
    cout << "\nUltimo valor: ";
    int ultimoValor;
    cin >> ultimoValor;
    cout << "\nCantidad de numeros primos que biscas: " << endl;
    int n;
    cin >> n;
    
    for(int i = primerValor; i < ultimoValor; ++i){
        int contador = 0;
        int hola;
        for(int j = 1; j < (1 + i);  ++j){
            int temp;
            temp = (i % j);
            if (temp == 0){
                contador ++;
            }
        }
            if(contador <= 2 && hola < n){
               numeros->insertFront(i);
               hola ++;
            }
    }
    
    /* Imprimir el contenido de la lista */
    std::cout << endl <<  *numeros << std::endl;
    return 0;
}
