#include <iostream>
#include <string.h>

using namespace std;

class Cliente{
public:
    string nombre;
    string apellido;
    int IFE;
    
public:
    Cliente();
    Cliente(string, string, int);
    void compra(string , int, int);
    
};
