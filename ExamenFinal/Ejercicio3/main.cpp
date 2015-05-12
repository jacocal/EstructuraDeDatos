
#include <iostream>
#include "BinaryTree.h"
#include <string.h>
using namespace std;


int main(int argc, const char * argv[]) {
    
    BinaryTree<char> numeros;
    
    int n;
    string caracteres;
    char a;
    cout << "Dame numero de valores que deseas ingresar" << endl;
    cin >> n;
    
    for(int i=0; i<n; ++i)
    {
        cout << "Dame caracteres" << endl;
        cin >> a;
        caracteres[i] = a;
    }
    
    
    BNode<char> * root = new BNode<char> (caracteres[0]);
    
    numeros.setRoot(root);
    
    for(int i=1; i<n; i+=2)
    {
        BNode<char> * temp = new BNode<char> (caracteres[i]);
        BNode<char> * temp2 = new BNode<char> (caracteres[i+1]);
        numeros.insert(root->getLeft(), temp);
        numeros.insert(root->getRight(), temp2);
    }
    
    numeros.preOrder();
    cout << endl;
    
    
    return 0;
}
