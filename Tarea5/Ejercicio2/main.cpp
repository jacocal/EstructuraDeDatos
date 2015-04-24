#include "../BinaryTree.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

  
    BinaryTree<int> tree;

    
    BNode<int> * one = new BNode<int>(1);
    tree.insert(nullptr, uno);
    
    
    BNode<int> * two = new BNode<int>(2);
    tree.insert(uno, dos);
    
    
    BNode<int> * three = new BNode<int>(3);
    tree.insert(uno, tres);
    
    BNode<int> * four = new BNode<int>(4);
    tree.insert(dos, cuatro);
    
    BNode<int> * five = new BNode<int>(5);
    tree.insert(dos, cinco);
    
        
    BNode<int> * six = new BNode<int>(10);
    tree.insert(tres, diez);
  
    std::cout << " ---- preOrder ----" << std::endl;
    tree.preOrder();
    std::cout << std::endl;
   

    numeros.reflex();
  
    std::cout << " ---- preOrder ----" << std::endl;
    tree.preOrder();
    std::cout << std::endl;
     
    
    
    return 0;
}
