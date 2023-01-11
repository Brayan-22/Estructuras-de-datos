/*
Brayan Alejandro Riveros Rodriguez 20201020084
David Cleves Guzman 20192020040
*/
#ifndef ESTRUCT_H
#define ESTRUCT_H
template<typename T>
struct nodo{
	T info;
	nodo<T> *ant;
	nodo<T> *sig;
};
#endif
