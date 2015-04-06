#ifndef sGAL_ArbolBinario_h
#define sGal_ArbolBinario_h

#include <iostream>
#include "NodoB.h"

template <class T>
class ArbolBinario {
    
    ArbolNodo<T> * raiz = NULL;
    
public:
    int altura(ArbolNodo<T> * nodo);
    
    ArbolBinario(ArbolNodo<T> * info);
    ~ArbolBinario();
    bool empty();
    void clear();
    void clear(ArbolNodo<T> * nodo);
    ArbolNodo<T> * getRaiz();
    void inOrden();
    void inOrden(ArbolNodo<T> * nodo);
    void preOrden();
    void preOrden(ArbolNodo<T> * nodo);
    void postOrden();
    void postOrden(ArbolNodo<T> * nodo);
    bool insert(T value, ArbolNodo<T> * padre);
    bool insert(T value, T padre);    
    ArbolNodo<T> * metodoA();
    ArbolNodo<T> * metodoA(ArbolNodo<T> * nodo);
    T metodoB(ArbolNodo<T> * nodo);
    void metodoB(ArbolNodo<T> * nodo, ArbolNodo<T> * acumulador);
    ArbolNodo<T> * getPadre(T info);
    ArbolNodo<T> * getPadre(T info, ArbolNodo<T> * nodo);
    bool mismoNivel(T nUno, T nDos);
    bool mismoNivel(ArbolNodo<T> * nUno, ArbolNodo<T> * nDos);
    void semejantes(ArbolNodo<T> * nodo, ArbolNodo<T> * raiz);
    ArbolNodo<T> * buscar (T info);
    ArbolNodo<T> * buscar (T info, ArbolNodo<T> * nodo);
    template <typename Tn>
    friend std::ostream& operator<<(std::ostream& os, ArbolBinario<Tn> &arbol);
    std::ostream& imprime(std::ostream& os, ArbolNodo<T> * nodo);
};

template <class T>
ArbolBinario<T>::ArbolBinario() { }

template <class T>
ArbolBinario<T>::ArbolBinario(ArbolNodo<T> * info) {
    raiz = info;
}

template <class T>
ArbolBinario<T>::~ArbolBinario() {
    clear(raiz);
}

template <class T>
void ArbolBinario<T>::clear() {
    clear(raiz);
}

template <class T>
void ArbolBinario<T>::clear(ArbolNodo<T> * nodo) {
    if (nodo) {
        clear(nodo->getIzquierdo());
        clear(nodo->getDerecho());
        delete nodo;
    }
}

template <class T>
bool ArbolBinario<T>::empty() {
    return (raiz == NULL);
}

template <class T>
ArbolNodo<T> * ArbolBinario<T>::getRaiz() {
    return raiz;
}

template <class T>
bool ArbolBinario<T>::insert(T value, T padre) {
    ArbolNodo<T> * padre_ptr = buscar(padre);
    if (padre_ptr)
        return insert(value, padre_ptr);
    return false;
}


template <class T>
bool ArbolBinario<T>::insert(T value, ArbolNodo<T> * padre) {
    if (!padre)
        raiz = new ArbolNodo<T>(value);
    else {
        if (!padre->getIzquierdo())
            padre->setIzquierdo(new ArbolNodo<T>(value));
        else if (!padre->getDerecho())
            padre->setDerecho(new ArbolNodo<T>(value));
        else
            return false;
    }
    return true;
}

template <class T>
void ArbolBinario<T>::preOrden() {
    preOrden(raiz);
}

template <class T>
void ArbolBinario<T>::preOrden(ArbolNodo<T> * nodo) {
    if (nodo) {
        std::cout << *nodo << " " << endl;
        preOrden(nodo->getIzquierdo());
        preOrden(nodo->getDerecho());
    }
}

template <class T>
void ArbolBinario<T>::inOrden() {
    inOrden(raiz);
}

template <class T>
void ArbolBinario<T>::inOrden(ArbolNodo<T> * nodo) {
    if (nodo) {
        inOrden(nodo->getIzquierdo());
        std::cout << *nodo << " ";
        inOrden(nodo->getDerecho());
    }
}

template <class T>
void ArbolBinario<T>::postOrden() {
    postOrden(raiz);
}
/*
template <class T>
void ArbolBinario<T>::postOrden(ArbolNodo<T> * nodo) {
    if (nodo = true) {
    postOrden(nodo->getDerecho());
        postOrden(nodo->getIzquierdo());
        std::cout << *nodo << " ";
    }
}
*/

template <class T>
int ArbolBinario<T>::altura(ArbolNodo<T> *nodo) 
{
    if (nodo == NULL)
    {
        return 0;
    }
    ArbolNodo<T> * aux = nodo;
    int altura = 1;
    while (getPadre(aux->getInfo())) 
    {
        ++altura;
        aux = getPadre(aux->getInfo());
    }
    return altura;
}

template <class T>
ArbolNodo<T> * ArbolBinario<T>::buscar(T info, ArbolNodo<T> * nodo)
{
    ArbolNodo<T> * encontrado = NULL;
    if (nodo) 
    {
        if (nodo->getInfo() == info)
        {
            return nodo;
        }
        else 
        {
            encontrado = buscar(info, nodo->getIzquierdo());
            if (encontrado)
            {
                return encontrado;
            }
            return buscar(info, nodo->getDerecho());
        }
    }
    return encontrado;
}

template <class T>
ArbolNodo<T> * ArbolBinario<T>::buscar(T info)
{
    return buscar(info, raiz);
}



template <class T>
ArbolNodo<T> * ArbolBinario<T>::getPadre(T info)
{
    return getPadre(info, raiz);
}

template <class T>
ArbolNodo<T> * ArbolBinario<T>::getPadre(T info, ArbolNodo<T> * nodo)
{
     ArbolNodo<T> * padre = NULL;
    if (nodo) 
    {
        if (nodo->getInfo() == info && nodo == raiz)
        {
            return NULL;
          }
        else if (nodo->getIzquierdo() && nodo->getIzquierdo()->getInfo() == info)
        {
            return nodo;
        z}
        else if (nodo->getDerecho() && nodo->getDerecho()->getInfo() == info)
        {
            return nodo;
        }
        else
        {
            padre = getPadre(info, nodo->getIzquierdo());
            if (padre = true)
            {
                return padre;
            }
            return getPadre(info, nodo->getDerecho());
        }
    }
    return padre;
}


template <class T>
bool ArbolBinario<T>::mismoNivel(ArbolNodo<T> * nUno, ArbolNodo<T> * nDos) 
{
    if (nUno == NULL || nDos == NULL)
    {
        return false;
    }
    return (getPadre(nUno->getInfo()) == nDos->getPadre(nDos->getInfo()));
}

template <class T>
bool ArbolBinario<T>::mismoNivel(T nUno, T nDos)
{
    return (getPadre(nUno) == getPadre(nDos));
}


template <class T>
ArbolNodo<T> * ArbolBinario<T>::metodoA() 
{
    return metodoA(raiz);
}

template <class T>
void ArbolBinario<T>::semejantes(ArbolNodo<T> *nodo, ArbolNodo<T> *raiz)
{
    if (raiz)
    {
        if (altura(nodo) == altura(raiz) && getPadre(nodo->getInfo()) != getPadre(raiz->getInfo())) 
        {
            std::cout << *raiz << " ";
        }
        semejantes(nodo, raiz->getIzquierdo());
        semejantes(nodo, raiz->getDerecho());
    }
}


template <class T>
ArbolNodo<T> * ArbolBinario<T>::metodoA(ArbolNodo<T> * nodo)
{
    T valor;
    if (nodo)
    {
        valor = nodo->getInfo();
        ArbolNodo<T> * metodoA_izq = metodoA(nodo->getIzquierdo());
        if (metodoA_izq) 
        {
            valor += metodoA_izq->getInfo();
            delete metodoA_izq;
        }
        
        ArbolNodo<T> * metodoA_der = metodoA(nodo->getDerecho());
        if (metodoA_der)
        {
            valor += metodoA_der->getInfo();
            delete metodoA_der;
        }
        return new ArbolNodo<T>(valor);
    }
    return NULL;
}


template <class T>
void ArbolBinario<T>::metodoB(ArbolNodo<T> * nodo, ArbolNodo<T> * acumulador) 
{
    if (nodo) 
    {
        acumulador->setInfo(acumulador->getInfo() + nodo->getInfo());
        metodoB(nodo->getIzquierdo(), acumulador);
        metodoB(nodo->getDerecho(), acumulador);
    }
}

template <class T>
T ArbolBinario<T>::metodoB(ArbolNodo<T> * nodo)
{
    ArbolNodo<T> * acumulador = new ArbolNodo<T>(0);
    metodoB(nodo, acumulador);
    T valor = acumulador->getInfo();
    delete acumulador;
    return valor;
}

template <class T>
T ArbolBinario<T>::suma() 
{
    return suma(raiz);
}

template <class T>
T ArbolBinario<T>::suma(ArbolNodo<T> *nodo)
{
    static T valor;
    if (nodo)
    {
        valor += nodo->getInfo();
        suma(nodo->getIzquierdo());
        suma(nodo->getDerecho());
    }
    return valor;
}

template <class T>
std::ostream& ArbolBinario<T>::imprime(std::ostream& os, ArbolNodo<T> * nodo) 
{
    if (nodo) 
    {
        os << *nodo << " ";
        imprime(os, nodo->getIzquierdo());
        imprime(os, nodo->getDerecho());
    }
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, ArbolBinario<T> &arbol) 
{
    return arbol.imprime(os, arbol.raiz);
}

#endif
