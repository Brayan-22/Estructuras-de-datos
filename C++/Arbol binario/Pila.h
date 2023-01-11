#ifndef PILA_H
#define PILA_H
#include "Estructura.h"
#include<iostream>
using namespace std;
template<typename T>
class pila{
	nodo<T> *frente;
	int tam;
	public:
		pila(){
			frente=NULL;
			tam=0;
		}
		void insertar(T inf);
		void sacar(T &elem);
		void imprimirPila();
		int getTam();
		bool isEmpty();
};
template<typename T>
int pila<T>::getTam(){
	return tam;
}
template<typename T>
bool pila<T>::isEmpty(){
	return ((tam==0)?true:false);
}
template<typename T>
void pila<T>::insertar(T inf){
	nodo<T> *nuevoNodo=new nodo<T>;
	nuevoNodo->info=inf;
	if(isEmpty()){
		nuevoNodo->sig=NULL;
		frente=nuevoNodo;
	}else{
		nuevoNodo->sig=frente;
		frente=nuevoNodo;
	}
	tam++;
}
template<typename T>
void pila<T>::sacar(T &elem){
	nodo<T> *aux;
	if(isEmpty()){
		cout<<"Cola vacia"<<endl;
	}else{
		elem=frente->info;
		aux=frente;
		frente=aux->sig;
		delete aux;
		tam--;
	}
}
template<typename T>
void pila<T>::imprimirPila(){
	nodo<T>*aux=frente;
	int i;
	for(i=0;i<getTam();i++){
		cout<<aux->info<<" ";
		aux=aux->sig;
	}
	cout<<endl;
}
#endif 
