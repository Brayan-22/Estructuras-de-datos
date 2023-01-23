#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include<iostream>
#include "Nodo.h"
#include "Cola.h"
#include "Pila.h"
template<typename T>
class arbolAVL{
    //private
    nodoAvl<T> *raiz;
    nodoAvl<T> *buscar(int clave);
    nodoAvl<T> *buscarPadre(nodoAvl<T> *hijo);
    void balancear(nodoAvl<T> *actual);
    void rotIzq(nodoAvl<T> *actual);
    void rotDer(nodoAvl<T> *actual);
    void inOrden(nodoAvl<T> *actual);
    void postOrden(nodoAvl<T> *actual);
    void preOrden(nodoAvl<T> *actual);    
    void insertar(nodoAvl<T> *actual,int clave,T info);
    int getAnchura(nodoAvl<T> *actual,int nivel);
    int altura(nodoAvl<T> *actual);
    int getFB(nodoAvl<T> *actual);
    public:
        arbolAVL(){this->raiz=NULL;}
        ~arbolAVL(){delete this->raiz;}
        bool insertar(int clave,T info);
        bool insertar(int clave);
        bool eliminar(int clave);
        bool busqueda(int clave);
        void inOrden();
        void postOrden();
        void preOrden();
        void niveles();
        bool isEmpty();
        int altura();
        int getAnchuraMaxima();
};

template<typename T>
int arbolAVL<T>::altura(nodoAvl<T> *actual){
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

template<typename T>
int arbolAVL<T>::getFB(nodoAvl<T> *actual){
    if (actual!=NULL)
    {
        return (altura(actual->der)-altura(actual->izq));
    }else{
        return 0;
    }
    
}

template<typename T>
void arbolAVL<T>::rotIzq(nodoAvl<T> *actual){
    nodoAvl<T> *aux=actual->der;
    if (actual==this->raiz)
    {
        this->raiz->der=aux->izq;
        aux->izq=this->raiz;
        this->raiz=aux;
    }else{
        nodoAvl<T> *padre=buscarPadre(actual);
        actual->der=aux->izq;
        aux->izq=actual;
        if(padre->der==actual)padre->der=aux;
        if(padre->izq==actual)padre->izq=aux;
    }
}

template<typename T>
void arbolAVL<T>::rotDer(nodoAvl<T> *actual){
    nodoAvl<T> *aux=actual->izq;
    if (actual==this->raiz)
    {
        this->raiz->izq=aux->der;
        aux->der=this->raiz;
        this->raiz=aux;
    }else{
        nodoAvl<T> *padre=buscarPadre(actual);
        actual->izq=aux->der;
        aux->der=actual;
        if(padre->der==actual)padre->der=aux;
        if(padre->izq==actual)padre->izq=aux;
    }
}

template<typename T>
void arbolAVL<T>::balancear(nodoAvl<T> *actual){
    if (actual!=NULL)
    {
        if (getFB(actual)>1)
        {
            if (getFB(actual->der)>=0)
            {
                rotIzq(actual);
            }
            if (getFB(actual->der)<0)
            {
                rotDer(actual->der);
                rotIzq(actual);
            }
        }else if(getFB(actual)<-1){
            if (getFB(actual->izq)<=0)
            {
                rotDer(actual);
            }
            if (getFB(actual->izq)>0)
            {
                rotIzq(actual->izq);
                rotDer(actual);
            }
        }else{
            actual=buscarPadre(actual);
            balancear(actual);
        }
    }
}

template<typename T>
void arbolAVL<T>::insertar(nodoAvl<T> *actual,int clave,T info){
    if (clave<actual->clave)
    {
        if (actual->izq==NULL)
        {
            nodoAvl<T> *nuevo = new nodoAvl<T>;
            nuevo->clave=clave;nuevo->info=info;nuevo->der=NULL;nuevo->izq=NULL;
            actual->izq=nuevo;
            balancear(actual);
        }else{
            insertar(actual->izq,clave,info);
        }
    }else{
        if (actual->der==NULL)
        {
            nodoAvl<T> *nuevo = new nodoAvl<T>;
            nuevo->clave=clave;nuevo->info=info;nuevo->der=NULL;nuevo->izq=NULL;
            actual->der=nuevo;
            balancear(actual);
        }else{
            insertar(actual->der,clave,info);
        }
    }
}

template<typename T>
bool arbolAVL<T>::insertar(int clave,T info){
    if (this->raiz==NULL)
    {
        nodoAvl<T> *nuevo = new nodoAvl<T>;
        nuevo->clave=clave;nuevo->info=info;nuevo->der=NULL;nuevo->izq=NULL;
        this->raiz=nuevo;
    }else{
        insertar(this->raiz,clave,info);
    }
    return true;
}

template<typename T>
bool arbolAVL<T>::insertar(int clave){
    if (this->raiz==NULL)
    {
        nodoAvl<T> *nuevo = new nodoAvl<T>;
        nuevo->clave=clave;nuevo->info=NULL;nuevo->der=NULL;nuevo->izq=NULL;        
        this->raiz=nuevo;
    }else{
        insertar(this->raiz,clave,NULL);
    }
    return true;
}

template<typename T>
bool arbolAVL<T>::eliminar(int clave){
    nodoAvl<T> * aux = this->buscar(clave);
    if (aux==NULL)return false;
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
            balancear(aux);
            return true;
        }
        if (aux->der!=NULL && aux->izq==NULL)
        {
            aux=aux->der;
            balancear(aux);
            return true;
        }
        nodoAvl<T> *aux2=aux;
        nodoAvl<T> *temp=aux->der;
        while (true)
        {
            if (temp->izq==NULL)
            {
                aux2->izq=temp->der;
                temp->izq=aux->izq;
                temp->der=aux->der;
                this->raiz=temp;
                balancear(this->raiz->der);
                return true;
            }
            aux2=temp;
            temp=aux2->izq;
        }
    }else{
        nodoAvl<T> *padre=buscarPadre(aux);
        if (padre->der==aux)
        {
            if ((aux->der==NULL)&&(aux->izq==NULL))
            {
                padre->der=NULL;
                balancear(padre);
                return true;
            }
            if (aux->der==NULL && aux->izq!=NULL)
            {
                padre->der=aux->izq;
                balancear(padre);
                return true;
            }
            if (aux->der!=NULL && aux->izq==NULL)
            {
                padre->der=aux->der;
                balancear(padre);
                return true;
            }
            if (aux->der!=NULL && aux->izq!=NULL)
            {
                nodoAvl<T> *aux2=aux;
                nodoAvl<T> *temp=aux->der;
                while (true)
                {
                    if (temp->izq==NULL)
                    {
                        aux2->izq=temp->der;
                        temp->izq=aux->izq;
                        temp->der=aux->der;
                        delete aux;
                        padre->der=temp;
                        balancear(padre->der);
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
                balancear(padre);
                return true;
            }
            if (aux->der==NULL && aux->izq!=NULL)
            {
                padre->izq=aux->izq;
                balancear(padre);
                return true;
            }
            if (aux->der!=NULL && aux->izq==NULL)
            {
                padre->izq=aux->der;
                balancear(padre);
                return true;
            }
            if (aux->der!=NULL && aux->izq!=NULL)
            {
                nodoAvl<T> *aux2=aux;
                nodoAvl<T> *temp=aux->der;
                while (true)
                {
                    if (temp->izq==NULL)
                    {
                        aux2->izq=temp->der;
                        temp->izq=aux->izq;
                        temp->der=aux->der;
                        delete aux;
                        padre->izq=temp;
                        balancear(padre->izq);
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

template<typename T>
bool arbolAVL<T>::isEmpty(){
    return ((this->raiz==NULL)?true:false);
}

template<typename T>
bool arbolAVL<T>::busqueda(int clave){
    nodoAvl<T> *actual = this->raiz;
    while (true)
    {
        if (actual==NULL)
        {
            return false;    
        }
        if (clave==actual->clave)
        {   
            return true;
        }
        if (actual!=NULL)
        {
            if (clave<actual->clave)
            {
                actual=actual->izq;
            }          
        }
        if (actual!=NULL)
        {
            if (clave>actual->clave)
            {
                actual=actual->der;
            }        
        }
    }
    
}

template<typename T>
nodoAvl<T> *arbolAVL<T>::buscar(int clave){
    nodoAvl<T> *actual = this->raiz;
    while (true)
    {
        if (actual==NULL)
        {
            return NULL;    
        }
        if (clave==actual->clave)
        {   
            return actual;
        }
        if (actual!=NULL)
        {
            if (clave<actual->clave)
            {
                actual=actual->izq;
            }          
        }
        if (actual!=NULL)
        {
            if (clave>actual->clave)
            {
                actual=actual->der;
            }        
        }
    }
}

template<typename T>
int arbolAVL<T>::altura(){
    return altura(this->raiz);
}

template<typename T>
int arbolAVL<T>::getAnchura(nodoAvl<T> *actual,int nivel){
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

template<typename T>
int arbolAVL<T>::getAnchuraMaxima(){
        int maxAnch = 0;
        int anchura;
        int altura = this->raiz->altura();

        for (int i = 1; i <= altura; i++) {
            anchura = getAnchura(this->raiz, i);
            if (anchura > maxAnch)
                maxAnch = anchura;
        }
        return maxAnch;
}

template<typename T>
nodoAvl<T> *arbolAVL<T>::buscarPadre(nodoAvl<T> *hijo){
    if (hijo==this->raiz)return NULL;
    nodoAvl<T> *padre;
    padre=this->raiz;
    while (true)
    {
        if (padre==NULL)return NULL;
        if (hijo->clave<padre->clave)
        {
            if ((padre->der==hijo)||(padre->izq==hijo))return padre;
            padre=padre->izq;
        }
        if (hijo->clave>padre->clave)
        {
            if ((padre->der==hijo)||(padre->izq==hijo))return padre;
            padre=padre->der;
        }
    }
    return NULL;
}

template<typename T>
void arbolAVL<T>::inOrden(nodoAvl<T> *actual){
    if (actual!=NULL)
    {
        inOrden(actual->izq);
        std::cout<<actual->clave<<" ";
        inOrden(actual->der);
    }
}

template<typename T>
void arbolAVL<T>::inOrden(){
    if (this->raiz==NULL)
    {
        std::cout<<"VACIO"<<std::endl;
    }
    inOrden(this->raiz);
    std::cout<<"\n";
}

template<typename T>
void arbolAVL<T>::postOrden(nodoAvl<T> *actual){
    if (actual!=NULL)
    {
        postOrden(actual->izq);
        postOrden(actual->der);
        std::cout<<actual->clave<<" ";
    }
}

template<typename T>
void arbolAVL<T>::postOrden(){
    if (this->raiz==NULL)
    {
        std::cout<<"VACIO"<<std::endl;
    }
    postOrden(this->raiz);
    std::cout<<"\n";
}

template<typename T>
void arbolAVL<T>::preOrden(nodoAvl<T> *actual){
    if (actual!=NULL)
    {
        std::cout<<actual->clave<<" ";
        preOrden(actual->izq);
        preOrden(actual->der);
    }
}

template<typename T>
void arbolAVL<T>::preOrden(){
    if (this->raiz==NULL)
    {
        std::cout<<"VACIO"<<std::endl;
    }
    preOrden(this->raiz);
    std::cout<<"\n";
}

template<typename T>
void arbolAVL<T>::niveles(){
    cola<nodoAvl<T> *> nuevaCola1;
    cola<int> nuevaCola2;
    nodoAvl<T> *actual=raiz;
    nodoAvl<T> *aux;
    int temp;
    nuevaCola1.encolar(actual);
    while (!nuevaCola1.isEmpty())
    {
        nuevaCola1.desencolar(aux);
        temp=aux->clave;
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