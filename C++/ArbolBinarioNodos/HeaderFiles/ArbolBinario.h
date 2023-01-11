#ifndef ARBOLBIN_H
#define ARBOLBIN_H
#include<iostream>
#include "Nodo.h"
#include "Cola.h"
#include "Pila.h"

class arbolBin{
    nodoABIN *raiz;
    nodoABIN *buscar(int info);
    nodoABIN *buscarPadre(nodoABIN *hijo);
    public:
    arbolBin(){
        raiz=NULL;        
    }
    ~arbolBin(){}
    bool insertar(int info);
    bool eliminar(int info);
    bool busqueda(int info);
    void inorden();
	void postorden();
    void preorden();
	void niveles();
};

bool arbolBin:: insertar(int info){
    nodoABIN *aux = new nodoABIN;
    aux->dato=info;
    aux->der=NULL;
    aux->izq=NULL;
    if(this->raiz==NULL){
        raiz=aux;
        std::cout<<info<<" insertado"<<std::endl;
        return true;
    }
    bool control=true;
    nodoABIN *temp =raiz;
    while (control)
    {
        if(info>=temp->dato){
            if(temp->der!=NULL){
                temp=temp->der;
            }else{
                temp->der=aux;
                std::cout<<info<<" insertado"<<std::endl;
                control=false;              
            }
        }
        if(info<temp->dato){
            if(temp->izq!=NULL){
                temp=temp->izq;
            }else{
                temp->izq=aux;
                std::cout<<info<<" insertado"<<std::endl;
                control=false;
            }
        }
    }
    return true;
}

bool arbolBin::busqueda(int info){
    nodoABIN *aux=raiz;
    while (true)
    {
        if (aux==NULL)
        {
            std::cout<<info<<" No encontrado"<<std::endl;
            return false;    
        }
        if (info==aux->dato)
        {   
            std::cout<<info<<" Encontrado"<<std::endl;
            return true;
        }
        if (aux!=NULL)
        {
            if (info<aux->dato)
            {
                aux=aux->izq;
            }          
        }
        if (aux!=NULL)
        {
            if (info>aux->dato)
            {
                aux=aux->der;
            }        
        }
    }
    return false;
}

nodoABIN *arbolBin::buscar(int info){
    nodoABIN *aux=raiz;
    bool control=true;
    while (control)
    {   
        if (aux==NULL)
        {
            std::cout<<info<<" No encontrado"<<std::endl;
            control=false;
            return NULL;    
        }
        if (info==aux->dato)
        {   
            std::cout<<info<<" Encontrado/eliminado"<<std::endl;
            control=false;
            return aux;
        }
        if (aux!=NULL)
        {
            if (info<aux->dato)
            {
                aux=aux->izq;
            }          
        }
        if (aux!=NULL)
        {
            if (info>aux->dato)
            {
                aux=aux->der;
            }        
        }
    }
    return NULL;
}

bool arbolBin::eliminar(int info){
    nodoABIN * aux = this->buscar(info);
    if (aux==NULL){
        //cout<<"No encontrado/imposible eliminar"<<endl;
        return false;
    }
    //SI EL NODO A ELIMINAR ES LA RAIZ DEL ARBOL
    if (aux==this->raiz)
    {
        if (aux->der==NULL && aux->izq==NULL)
        {
            aux==NULL;
            return true;
        }
        if (aux->der==NULL && aux->izq!=NULL)
        {
            aux=aux->izq;
            return true;
        }
        if (aux->der!=NULL && aux->izq==NULL)
        {
            aux=aux->der;
            return true;
        }
        nodoABIN *aux2=aux;
        nodoABIN *temp=aux->der;
        while (true)
        {
            if (temp->izq==NULL)
            {
                aux2->izq=temp->der;
                temp->izq=aux->izq;
                temp->der=aux->der;
                this->raiz=temp;
                return true;
            }
            aux2=temp;
            temp=aux2->izq;
        }
    }else{
        nodoABIN *padre=buscarPadre(aux);
        if (padre->der==aux)
        {
            if ((aux->der==NULL)&&(aux->izq==NULL))
            {
                padre->der=NULL;
                return true;
            }
            if (aux->der==NULL && aux->izq!=NULL)
            {
                padre->der=aux->izq;
                return true;
            }
            if (aux->der!=NULL && aux->izq==NULL)
            {
                padre->der=aux->der;
                return true;
            }
            if (aux->der!=NULL && aux->izq!=NULL)
            {
                nodoABIN *aux2=aux;
                nodoABIN *temp=aux->der;
                while (true)
                {
                    if (temp->izq==NULL)
                    {
                        aux2->izq=temp->der;
                        temp->izq=aux->izq;
                        temp->der=aux->der;
                        delete aux;
                        padre->der=temp;
                        return true;
                    }
                    aux2=temp;
                    temp=aux2->izq;
                }
            }
        }
        if (padre->izq==aux)
        {
            if ((aux->der==NULL)&&(aux->izq==NULL))
            {
                padre->izq=NULL;
                return true;
            }
            if (aux->der==NULL && aux->izq!=NULL)
            {
                padre->izq=aux->izq;
                return true;
            }
            if (aux->der!=NULL && aux->izq==NULL)
            {
                padre->izq=aux->der;
                return true;
            }
            if (aux->der!=NULL && aux->izq!=NULL)
            {
                nodoABIN *aux2=aux;
                nodoABIN *temp=aux->der;
                while (true)
                {
                    if (temp->izq==NULL)
                    {
                        aux2->izq=temp->der;
                        temp->izq=aux->izq;
                        temp->der=aux->der;
                        delete aux;
                        padre->izq=temp;
                        return true;
                    }
                    aux2=temp;
                    temp=aux2->izq;
                }
            }
        }
    }
}

nodoABIN *arbolBin::buscarPadre(nodoABIN *hijo){
    if (hijo==this->raiz)return NULL;
    
    nodoABIN *padre;
    padre=this->raiz;
    bool control=true;
    while (control)
    {
        if (padre==NULL)return NULL;
        if (hijo->dato<padre->dato)
        {
            if ((padre->der==hijo)||(padre->izq==hijo)){control=false;return padre;}
            nodoABIN *temp=padre;
            padre=temp->izq;
        }
        if (hijo->dato>padre->dato)
        {
            if ((padre->der==hijo)||(padre->izq==hijo)){control=false;return padre;}
            nodoABIN *temp=padre;
            padre=temp->der;
        }
    }
    return NULL;
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