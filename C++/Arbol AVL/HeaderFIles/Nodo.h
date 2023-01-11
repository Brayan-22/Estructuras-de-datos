#ifndef NODO_H
#define NODO_H

struct nodoABase{
    int dato;
    nodoABase *izq;
    nodoABase *der;
};

struct nodoAVL {
    int dato;
    int f_bal;
    nodoAVL *izq;
    nodoAVL *der;
};

template<typename T>
struct nodo{
	T info;
	nodo<T> *sig;
};
#endif