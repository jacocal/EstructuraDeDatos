#ifndef EjercicioExtra_Libro_h
#define EjercicioExtra_Libro_h

#include <iostream>
#include <string.h>
#include <ostream>
using namespace std;

class Libro
{
    
    int numPag;
    int altura;
    string nombre;
public:
    Libro();
    Libro(int, int, string);
    bool operator >(Libro & libro);
    bool operator <(Libro & libro);
    int getAltura();
    
    friend ostream & operator << (ostream & os, const Libro & libro);
    
};


#endif
