#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include<iostream>
#include "Nodo.h"
#include "Cola.h"
#include "Pila.h"
class arbolAvl{
    nodoAVL *raiz;
    public:
    arbolAvl(){
        raiz=NULL;        
    }
    ~arbolAvl(){}
    bool insertar(int info);
    bool eliminar(int info);
    //bool eliminar();
    void inorden();
	void postorden();
    void preorden();
	void niveles();
};

bool arbolAvl:: insertar(int info){
    nodoAVL *aux = new nodoAVL;
    aux->dato=info;
    aux->der=NULL;
    aux->izq=NULL;
    if(this->raiz==NULL){
        raiz=aux;
        return true;
    }
    bool control=true;
    nodoAVL *temp =raiz;
    nodoAVL *temp2;
    while (control)
    {
        if(info>=temp->dato){
            if(temp->der!=NULL){
                temp=temp->der;
            }else{
                temp->der=aux;
                control=false;              
            }
        }
        if(info<temp->dato){
            if(temp->izq!=NULL){
                temp=temp->izq;
            }else{
                temp->izq=aux;
                control=false;
            }
        }
    }
    return true;
}

bool arbolAvl::eliminar(int info){

    
    return;
}
void arbolAvl::inorden(){
	pila<nodoAVL *> nuevaPila;
	cola<int> nuevaCola;
	int temp;
	nodoAVL *actual=raiz;
	nodoAVL *aux;
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

void arbolAvl::postorden(){
    pila<nodoAVL *> nuevaPila;
    cola<int> nuevaCola;
    int temp;
    nodoAVL *actual=raiz;
    nodoAVL *aux;
    nodoAVL *ultimoNodoVisitado=NULL;
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

void arbolAvl::preorden(){
    pila<nodoAVL *> nuevaPila;
    cola<int> nuevaCola;
    int temp;
    nodoAVL *actual=raiz;
    nodoAVL *aux;
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

void arbolAvl::niveles(){
    cola<nodoAVL *> nuevaCola1;
    cola<int> nuevaCola2;
    nodoAVL *actual=raiz;
    nodoAVL *aux;
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