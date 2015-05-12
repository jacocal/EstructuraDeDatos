#include <iostream>
#include <string>
#include <ostream>
#include <list>

class Persona {
private:
    std::string nombre;
    std::string apellidos;
    int tiempoRelacion;
    int tiempoSoledad;
    std::list<Persona> amigos;
    
public:
    Persona() : Persona("", "", 0, 0) {}
    Persona(std::string _nombre, std::string _apellidos , int _tiempoRelacion, int _tiempoSoledad) : nombre(_nombre), apellidos(_apellidos), tiempoRelacion(_tiempoRelacion), tiempoSoledad(_tiempoSoledad){}
    
    int getTiempoRelacion();
    void setTiempoRelacion(int tiempo);
    int getTiempoSoledad();
    void setTiempoSoledad(int tiempo);
    std::string getNombre();
    std::string getApellido();
    Persona relacionMasEstable();
    int calculaTiempoSoledad(Persona persona);
    int calculaTiempoRelacion(Persona persona);
    
    
    bool operator >(Persona & persona);
    bool operator <(Persona & persona);
    bool operator  == (Persona & persona);
    
    void agregarAmigo(Persona persona);
    void imprimeLista();
    int getSizeList();
    std::list<Persona> getLista();
    
    friend std::ostream & operator << (std::ostream & os, const Persona & persona);
    
};

void Persona::setTiempoSoledad(int tiempo){
    this->tiempoSoledad += tiempo;
}

void Persona::setTiempoRelacion(int tiempo){
    this->tiempoRelacion += tiempo;
}

int Persona::getTiempoRelacion(){
    return tiempoRelacion;
}

int Persona::getTiempoSoledad(){
    return tiempoSoledad;
}

int Persona::calculaTiempoRelacion(Persona persona){
    int x = persona.getTiempoRelacion();
    int porcentaje = (x * 100) / 1440;
    return porcentaje;
}

int Persona::calculaTiempoSoledad(Persona persona){
    int x = calculaTiempoRelacion(persona);
    int porcentaje = 100 - x;
    return porcentaje;
}





std::string Persona::getApellido(){
    return apellidos;
}

std::string Persona::getNombre(){
    return nombre;
}

void Persona::imprimeLista(){
    for(auto mar : amigos){
        std::cout << mar << std::endl;    
    }
    
}
 
int Persona::getSizeList(){
    return amigos.size();
}

std::list<Persona> Persona::getLista(){
    return amigos;
}

bool Persona::operator >(Persona & persona)
{
    if (apellidos > persona.apellidos) {
        
        return true;
    }
    else if (apellidos == persona.apellidos) {
    
        if (nombre < persona.nombre) {
            return true;
        }
        else {
            return false;
        }
    }
    
    return false;
}
/*
bool Persona::operator <(Persona & persona)
{
    return edad < persona.edad;
}
*/
std::ostream & operator << (std::ostream & os,  const Persona & persona)
{
    os << persona.nombre << "  "<< persona.apellidos << "\n Tiempo de Relacion: " << persona.tiempoRelacion << "\n Tiempo de Soledad: " << persona.tiempoSoledad << std::endl;
    
    return os;
}

bool Persona::operator  == (Persona & persona){
    if(persona.nombre == nombre && persona.apellidos == apellidos){
        return true;
    }else {
        return false;
    }
}


void Persona::agregarAmigo(Persona persona){
    amigos.push_back(persona);
}
