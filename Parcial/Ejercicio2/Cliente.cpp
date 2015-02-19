#include "Cliente.h"
#include "Auto.h"
#include "Moto.h"
#include "Camioneta.h"

Cliente::Cliente(){
    
}

Cliente::Cliente(string nom, string ape, int iD){
    nom = nombre;
    ape = apellido;
    iD = IFE;
}

void Cliente::compra(string tipo, int monto, int codigo){
    
    int i = 0;
    string type[i] = tipo;
    int amount[i] = monto;
    int code[i] = codigo;
    
}
