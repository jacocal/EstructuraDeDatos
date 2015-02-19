#include <iostream>
#include <string.h>

using namespace std;

class Consesaria{
private:
    int monto[];
    string vehiculoVendido[];
    string compradorNombre[];
    string compradorApellido[];
    int compradorIFE[];
    
public:
    string getNombre();
    string getApellido();
    int getIFE();
    string getVehiculo();
    void compra(string, string, int, int);
};
