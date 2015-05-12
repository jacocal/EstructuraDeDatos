#include <iostream>
#include <string>
#include "Persona.h"
#include <list>
using namespace std;

void navega(Persona persona);


list<Persona> personas;
    
int main(){
    int whilb = 0;
    while(whilb != 777){
        cout << " 1. iniciar sesion\n 2. Registrarte\n 3. Salir" << endl;
        int op;
        cin >> op;
        if (op == 1){
            //inicia sesion
            cout << "Nombre: " ;
            string nombre;
            cin.ignore();
            getline(cin,nombre);
            
            cout << "Apellido: " ;
            string apellido;
            cin >> apellido;
            
            Persona amigo;
            
                                    

            for (auto mar : personas){
                if( mar.getNombre() == nombre && mar.getApellido() == apellido){
                    amigo = mar;
                    //cout << endl;
                    //cout << "Bienvend@   " << persona.getNombre() << "  " << persona.getApellido() << endl;
                    
                    navega(amigo);
                }else{
                    cout << "no te has dado de alta!" << endl;
                }
            }
        
            //validaPersona(persona);
        
            
            
        }else if(op == 2){
            //Registrate
            cout << "Nombre: " ;
            string nombre;
            cin.ignore();
            getline(cin,nombre);
            
            cout << "Apellido: " ;
            string apellido;
            cin >> apellido;
            
            Persona persona(nombre, apellido, 0, 0);
            personas.push_back(persona);
            
            navega(persona);

            
        }else if(op == 3){
            whilb = 777;
        }else{
            cout << "pon una opcion real" << endl;
        }
       
    }

    
    
    return 0;
}




void navega(Persona persona){
    int whilo = 0;
    while(whilo != 666){
        cout << "1. Eres una persona nueva a analizar \n2. Tienes un nuevo amigo" << endl;
        //cout << "3.- Quieres saber tus porcentajes de tiempo (Solito o acompañado)" << endl;
        cout << "5. Nominaciones" << endl;
        cout << "6. Salir" << endl;
        int op;
        cin >> op;
        switch(op){
            case 1:
                whilo = 666;
                break;
            
            break;
            
            case 2:{
                cout << "Nombre de tu amigo: " ;
                string nombre;
                cin.ignore();
                getline(cin,nombre);
                
                cout << "Apellido de tu amigo: " ;
                string apellido;
                cin >> apellido;
                bool registrado = false;
                
                Persona amigo;

                for (auto mar : personas){
                    if( mar.getNombre() == nombre && mar.getApellido() == apellido){
                        amigo = mar;
                        //cout << endl;
                        //cout << "Bienvend@   " << persona.getNombre() << "  " << persona.getApellido() << endl;
                        registrado = true;
                        
                    }
                }
                if(!registrado){
                    cout << "No existe esa persona" << endl;
                    whilo = 666;
                    break;
                } 
                
                cout << "Tiempo que pasaste con tu amigo (en minutos)" << endl;
                int minutos;
                cin >> minutos;
                
                persona.agregarAmigo(amigo);
                persona.setTiempoRelacion(minutos);
                amigo.setTiempoRelacion(minutos);
                persona.setTiempoSoledad(1440 - minutos);
                amigo.setTiempoSoledad(1440 - minutos);
                 
                cout << "porcentaje de relacion: " << amigo.calculaTiempoRelacion(amigo)<< endl;
                cout << "Porcentaje soledad: " << amigo.calculaTiempoSoledad(amigo) << endl;
                
                
            }
            break;
            
            case 3:{
                cout << "Nombre: " ;
                string nombre;
                cin.ignore();
                getline(cin,nombre);
                
                cout << "Apellido: " ;
                string apellido;
                cin >> apellido;
                
                Persona amigo;
                
                int whila = 0;
                bool registrado = false;

                    for (auto mar : personas){
                        if( mar.getNombre() == nombre && mar.getApellido() == apellido){
                            amigo = mar;
                            //cout << endl;
                            //cout << "Bienvend@   " << persona.getNombre() << "  " << persona.getApellido() << endl;
                            registrado = true;
                        }
                    }
                    if(!registrado){
                        cout << "No existe esa persona" << endl;
                        //whilo = 666;
                        //break;
                    } 
                
                cout << "porcentaje de relacion: " << amigo.calculaTiempoRelacion(amigo)<< endl;
                cout << "Porcentaje soledad: " << amigo.calculaTiempoSoledad(amigo) << endl;
            }
            break;
            
            case 5:{
                int elTiempoMasAmoroso = 0;
                Persona elMasAmoroso;
                for(auto x : personas){
                    if(x.getTiempoRelacion() > elTiempoMasAmoroso){
                        elMasAmoroso = x; 
                    }
                }
                cout << "El mas amoroso es: " << endl;
                cout << elMasAmoroso.getNombre() << endl;
            }
            break;
            
            case 6:{
                whilo = 666;
                return;
            }
                 
            break;
            
            default:
                cout << "Pon una opcion correcta" << endl;
            break;
        }
    }
}
