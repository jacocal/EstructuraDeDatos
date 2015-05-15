#include <iostream>
#include "Libro.h"
#include <algorithm>
#include "OrdenamientoGenerico.h"

int main(int argc, const char * argv[]) {
    
    const int n = 3; //estantes
    const int m = 10; //numero de libros
    const int k = 4;
    
    //int estante[m];
    
    Libro libro[m];
    
    libro[0] = Libro(55, 5, "A");
    libro[1] = Libro(55, 8, "B");
    libro[2] = Libro(55, 14, "C");
    libro[3] = Libro(55, 20, "D");
    libro[4] = Libro(55, 3, "E");
    libro[5] = Libro(55, 5, "F");
    libro[6] = Libro(55, 7, "G");
    libro[7] = Libro(55, 8, "H");
    libro[8] = Libro(55, 9, "I");
    libro[9] = Libro(55, 10, "J");
    
    Ordenamiento<Libro>::seleccion(libro, m, [](Libro a, Libro b){ return a > b;});
    
    int a = 0;
    
    
        for(int i=n; i>1; --i)
        {
            for(int j=k; j>1; --j)
            {
                for(int l=(n-1); l>0; --l)
                {
                    a+= (libro[l].getAltura() - libro[l-1].getAltura());
                }
            }
        }
    
    for(int i=1; i<=n; ++i){
        cout << k << " se encuentran en el estante: " << i << endl;
    }
    copy(libro, libro+m, ostream_iterator<Libro>(std::cout, ""));
    
    cout << a << endl;
    
    int c;
    cout << "Dame posicion" << endl;
    cin >> c;
    
    cout << libro[c-1] << endl;
    
    
    
    return 0;
}
