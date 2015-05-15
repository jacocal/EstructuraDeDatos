#include "Libro.h"

Libro::Libro()
{
    
}

Libro::Libro(int numPag, int altura, string nombre)
{
    this->numPag = numPag;
    this->altura = altura;
    this->nombre = nombre;
}

int Libro::getAltura()
{
    return altura;
}

bool Libro::operator >(Libro & libro)
{
    if (altura > libro.altura) {
        
        return true;
    }
    else if (altura == libro.altura) {
        return false;
    }else{
        return false;
    }
}

bool Libro::operator <(Libro & libro)
{
    return altura < libro.altura;
}

ostream & operator << (ostream & os,  const Libro & libro)
{
    os << libro.numPag << ", " << libro.altura << "(" << libro.nombre << ")" << endl;
    
    return os;
}
