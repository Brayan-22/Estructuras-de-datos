#ifndef NODO_H
#define NODO_H
#include<iostream>
template<typename T>
struct nodoAvl{
    int fb;
    int clave;
    T info;
    nodoAvl<T> *izq=NULL;
    nodoAvl<T> *der=NULL;
};

template<typename T>
struct nodo{
	T info;
	nodo<T> *sig;
};
#endif