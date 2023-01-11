#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H
struct nodoArbol{
	int clave;
	int Hizq;
	int Hder;	
};
template<typename T>
struct nodo{
	T info;
	nodo<T> *sig;
};
#endif
