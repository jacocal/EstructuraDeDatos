#ifndef __ordenamientoGenerico__Persona__
#define __ordenamientoGenerico__Persona__

#include <iostream>
#include <string>
#include <ostream>

class Persona {
private:
    std::string nombre;
    std::string apellidos;
    int edad;
    int fNacimiento;
    
public:
    Persona() : Persona("", "", 0, 0) {}
    Persona(std::string _nombre, std::string _apellidos , int _edad, int _fNacimiento) : nombre(_nombre), apellidos(_apellidos), edad(_edad), fNacimiento(_fNacimiento) {}
    
    bool operator >(Persona & persona);
    bool operator <(Persona & persona);
    
    friend std::ostream & operator << (std::ostream & os, const Persona & persona);
    
};
#endif
