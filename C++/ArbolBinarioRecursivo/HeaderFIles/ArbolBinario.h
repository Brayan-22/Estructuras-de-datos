#ifndef ARBOLBIN_H
#define ARBOLBIN_H
#include <iostream>
#include "./HeaderFiles/Cola.h"
#include "./HeaderFiles/Pila.h"
using namespace std;
struct nodo{
	int clave;
	nodo *izq;
	nodo *der;
}

class arbolBin{
	nodo *raiz;
	nodo *insertarRecursivo(*nodo actual,int clave);
	public:
		arbolBin(){
			this->raiz=NULL;
		}
	void insertar(int clave);
	//bool eliminar(int clave);
	//bool busqueda(int clave);
	//Recorridos
	void inorden();
	void postorden();
	void preorden();
	void niveles();
};
nodo *arbolBin::insertarRecursivo(*nodo actual,int clave){
	if(actual==NULL){
		nodo *nuevo=new nodo;
		nuevo->clave=clave;
		nuevo->der=null;
		nuevo->izq=null;
		return nuevo;
	}
	if(clave<actual->clave){
		actual->izq=insertarRecursivo(actual->izq,clave);
	}else if(clave>=actual->clave){
		actual->der=insertarRecursivo(actual->der,clave);
	}else{
		return actual;
	}
}
void arbolBin::insertar(int clave){
	this->raiz=insertarRecursivo(raiz,clave);
}
void arbolBin::inorden(){
	pila<nodoABIN *> nuevaPila;
	cola<int> nuevaCola;
	int temp;
	nodoABIN *actual=raiz;
	nodoABIN *aux;
	bool control=true;
	while(control){
		if(actual!=NULL){
			aux=actual;
			nuevaPila.insertar(actual);
			actual=aux->izq;
		}else if(actual==NULL && nuevaPila.isEmpty()==false){
			nuevaPila.sacar(aux); 
			temp=aux->dato;
			nuevaCola.encolar(temp);
			actual=aux->der;
		}else{
			control=false;
		}
	}
    int count = nuevaCola.getTam();
    int imp;
    for (size_t i = 0; i < count; i++)
    {
        nuevaCola.desencolar(imp);
        std::cout<<imp<<" ";
    } 
    std::cout<<std::endl;
}

void arbolBin::postorden(){
    pila<nodoABIN *> nuevaPila;
    cola<int> nuevaCola;
    int temp;
    nodoABIN *actual=raiz;
    nodoABIN *aux;
    nodoABIN *ultimoNodoVisitado=NULL;
    bool control=true;
    while (!nuevaPila.isEmpty() || actual!=NULL)
    {
        if (actual!=NULL)
        {
            aux=actual;
            nuevaPila.insertar(aux);
            actual=aux->izq;
        }else
        {
            nuevaPila.sacar(aux);
            nuevaPila.insertar(aux);
            if (aux->der!=NULL && ultimoNodoVisitado!=aux->der)
            {
                actual=aux->der;
            }else
            {
                temp=aux->dato;
                nuevaCola.encolar(temp);
                nuevaPila.sacar(ultimoNodoVisitado);
            }
        }
    }
    int count = nuevaCola.getTam();
    int imp;
    for (size_t i = 0; i < count; i++)
    {
        nuevaCola.desencolar(imp);
        std::cout<<imp<<" ";
    } 
    std::cout<<std::endl;
}

void arbolBin::preorden(){
    pila<nodoABIN *> nuevaPila;
    cola<int> nuevaCola;
    int temp;
    nodoABIN *actual=raiz;
    nodoABIN *aux;
    bool control=true;
    while (control)
    {
        if (actual!=NULL)
        {
            aux=actual;
            temp=aux->dato;
            nuevaCola.encolar(temp);
            nuevaPila.insertar(aux);
            actual=aux->izq;
        }else if (actual==NULL && nuevaPila.isEmpty()==false)
        {
            nuevaPila.sacar(aux);
            actual=aux->der;
        }else
        {
            control=false;
        }
    }
    int count = nuevaCola.getTam();
    int imp;
    for (size_t i = 0; i < count; i++)
    {
        nuevaCola.desencolar(imp);
        std::cout<<imp<<" ";
    } 
    std::cout<<std::endl;
}

void arbolBin::niveles(){
    cola<nodoABIN *> nuevaCola1;
    cola<int> nuevaCola2;
    nodoABIN *actual=raiz;
    nodoABIN *aux;
    int temp;
    nuevaCola1.encolar(actual);
    while (!nuevaCola1.isEmpty())
    {
        nuevaCola1.desencolar(aux);
        temp=aux->dato;
        nuevaCola2.encolar(temp);
        if (aux->izq!=NULL)
        {
            nuevaCola1.encolar(aux->izq);
        }
        if (aux->der!=NULL)
        {
            nuevaCola1.encolar(aux->der);
        }
    }
    int count = nuevaCola2.getTam();
    int imp;
    for (size_t i = 0; i < count; i++)
    {
        nuevaCola2.desencolar(imp);
        std::cout<<imp<<" ";
    } 
    std::cout<<std::endl;
}
#endif
