#ifndef ARBOLBIN_H
#define ARBOLBIN_H
#include<iostream>
#include "Nodo.h"
#include "Cola.h"
#include "Pila.h"

class arbolBin{
    //private
    nodoABIN *raiz;
    nodoABIN *buscar(int info);
    nodoABIN *buscarPadre(nodoABIN *hijo);
    int altura(nodoABIN *actual);
    void insertar(nodoABIN *actual,int info);
    int getAnchura(nodoABIN *actual,int nivel);
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
    bool isEmpty();
    int altura();
    int getAnchuraMaxima();
};

void arbolBin::insertar(nodoABIN *actual,int info){
    if (info<actual->dato)
    {
        if (actual->izq==NULL)
        {
            nodoABIN *nuevo=new nodoABIN;
            nuevo->dato=info;nuevo->der=NULL;nuevo->izq=NULL;
            actual->izq=nuevo;
        }else{
            insertar(actual->izq,info);
        }
    }else{
        if (actual->der==NULL)
        {
            nodoABIN *nuevo=new nodoABIN;
            nuevo->dato=info;nuevo->der=NULL;nuevo->izq=NULL;
            actual->der=nuevo;
        }else{
            insertar(actual->der,info);
        }
    }
}

bool arbolBin:: insertar(int info){
    if (this->raiz==NULL)
    {
        nodoABIN *nuevo=new nodoABIN;
        nuevo->dato=info;nuevo->der=NULL;nuevo->izq=NULL;
        this->raiz=nuevo;
    }else{
        insertar(this->raiz,info);
    }
    return true;
}

bool arbolBin::isEmpty(){
    return ((this->raiz==NULL)?true:false);
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
            aux=NULL;
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
    return false;
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

/*Funciones utiles */
/* Calcular la "altura" de un árbol 
-- el número de nodos a lo largo del camino más largo desde el nodo raíz hasta el nodo hoja más lejano.
*/
int arbolBin::altura(nodoABIN *actual){
    if (actual==NULL)
    {
        return 0;
    }else{
        /* calcular la altura de cada subarbol*/
        int izqAltura = altura(actual->izq);
        int derAltura = altura(actual->der);
        /* retornar el mas "alto" */
        return (izqAltura > derAltura)?(izqAltura + 1):(derAltura + 1);
    }
}

int arbolBin::altura(){
    return altura(this->raiz);
}

/* Obtener el ancho de un nivel dado */
int arbolBin::getAnchura(nodoABIN *actual,int nivel){
    if (actual == NULL){
        return 0;
    }
    if (nivel == 1){
        return 1;
    }else if (nivel > 1){
        return getAnchura(actual->izq, nivel - 1) + getAnchura(actual->der, nivel - 1);
    }
    return 0;
}

int arbolBin::getAnchuraMaxima(){
            int maxAnch = 0;
        int anchura;
        int altura = this->altura(this->raiz);
        /*  Obteniendo el ancho de cada nivel 
            y comparar el ancho con el ancho máximo hasta ahora
        */
        for (int i = 1; i <= altura; i++) {
            anchura = getAnchura(this->raiz, i);
            if (anchura > maxAnch)
                maxAnch = anchura;
        }
        return maxAnch;
}

#endif