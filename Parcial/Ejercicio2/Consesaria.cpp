#include "Consesaria.h"
#include "Cliente.h"
#include "Auto.h"
#include "Moto.h"
#include "Camioneta.h"

Cliente l;

string Consesaria::getNombre(){
    nombre = l.nombre;
}

string Consesaria::getApellido(){
    apellido = l.apellido;
}

int Consesaria::getIFE(){
    IFE = l.IFE;
}


