#ifndef COLA_H
#define COLA_H
#include "Estructura.h"
#include<iostream>
using namespace std;
template<typename T>
class cola{
	nodo<T> *frente;
	nodo<T> *final;
	int tam;
	public:
		cola(){
			frente=NULL;
			final=NULL;
			tam=0;
		}
		void encolar(T inf);
		void desencolar(T &elem);
		int getTam();
		bool isEmpty();
};
template<typename T>
int cola<T>::getTam(){
	return tam;
}
template<typename T>
bool cola<T>::isEmpty(){
	return ((tam==0)?true:false);
}
template<typename T>
void cola<T>::encolar(T inf){
	nodo<T> *nuevoNodo=new nodo<T>;
	nuevoNodo->info=inf;
	nuevoNodo->sig=NULL;
	if(isEmpty()){
		frente=nuevoNodo;
		final=nuevoNodo;
	}else{
		final->sig=nuevoNodo;
		final=nuevoNodo;
	}
	tam++;
}
template<typename T>
void cola<T>::desencolar(T &elem){
	nodo<T> *aux;
	if(isEmpty()){
		cout<<"Cola vacia"<<endl;
	}else{
		aux=frente;
		elem=aux->info;
		frente=aux->sig;
		delete aux;
		tam--;
	}
}
#endif 
