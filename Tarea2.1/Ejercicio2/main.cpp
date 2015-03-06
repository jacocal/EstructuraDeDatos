#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;

int main(){
    
        
    LinkedList<int> * N = new LinkedList<int>();
    LinkedList<int> * M = new LinkedList<int>();
    LinkedList<int> * P = new LinkedList<int>();
    
    
    cout << "Hola! empezaremos llenando la lista ´N´ " << endl;
    cout << "Cuantos numeros deceas meter en N ? " ;
    int longitudN;
    cin >> longitudN;
    for (int i = 0; i < longitudN ; ++i){
        cout << "pon número:  ";
        int numero;
        cin >> numero;
        N->insertBack(numero);
    }
    cout << "Listo, ahora haremos la lista ´M´ " << endl;
    cout << "Cuantos numeros deceas meter en M ? " ;
    int longitudM;
    cin >> longitudM;
    for (int i = 0; i < longitudM ; ++i){
        cout << "pon número:  ";
        int numero;
        cin >> numero;
        M->insertBack(numero);
    }
    

    cout << "Tu lista N contiene: " << endl;
    cout << *N << endl;
    cout << "Tu lista M contiene: " << endl;
    cout << *M << endl;
    
    
    cout << "Que deseas hacer?\n 1.- N ⋃ M\n 2.- N - M\n 3.- M - N\n 4.- N * M\n 5.- N ⋂ M \n 6.- Nada" << endl;
    int op;
    int tam;
    if(longitudM > longitudN){
        tam = longitudN;
    }else{
        tam = longitudM;
    }
    //cout << tam;
    cin >> op;
    switch(op){
        case 1:{
            int n;
            for (int i = 0; i < longitudN; ++i){
                n = N->at(i)->getInfo();
                P->insertBack(n);
            }
            
            for (int i = 0; i < longitudM; ++i){
                n = M->at(i)->getInfo();
                if (!P->search(n)){
                    P->insertBack(n);    
                }
            }
            cout << *P << endl;
        }
        break;
        
        case 2:{
            for(int i = 0; i < longitudN; ++i){
                if(!M->search(N->at(i)->getInfo())){
                    P->insertBack(N->at(i)->getInfo());  
                }
            }    
        }
        break;
        
        case 3:{
            for(int i = 0; i < longitudM; ++i){
                if(!N->search(M->at(i)->getInfo())){
                    P->insertBack(M->at(i)->getInfo());  
                }
            }  
        }
        
        break;
        
        case 4:
            for(int i = 0; i < longitudN; ++i){
                for(int j = 0; j < longitudM; ++j){
                    int numi;
                    numi = N->at(i)->getInfo() * M->at(j)->getInfo();
                    P->insertBack(numi);
                }
            }
        
        break;
        
        case 5:{
          for(int i = 0; i < tam; ++i){
                if(N->search(M->at(i)->getInfo())){
                    P->insertBack(M->at(i)->getInfo());  
                }
            }
            
        }
        
        break;
        
        case 6:
            cout << "bye" << endl;
        break;
        
        default:
            cout << "Pon una opcion valida" << endl;
        break;
    }
    
    
    cout << endl << *P << endl;
    
    delete M;
    delete N;
    delete P;
    
    return 0;
}
