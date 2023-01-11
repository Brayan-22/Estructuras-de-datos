/*
Brayan Alejandro Riveros Rodriguez 20201020084
David Cleves Guzman 20192020040
*/
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
		~cola(){}
		/*------------------------Añadir a la cola-----------------------------*/
		//pos: I:encolar desde la izquierda o frente de la cola
		//	   D:encolar desde la derecha o final de la cola
		void enqueue(T inf,char pos);
		/*------------------------Sacar de la cola-----------------------------*/
		void dequeue(T &inf,char pos);
		//Metodo si solo se quiere desencolar un elemento sin saber su valor
		void dequeue(char pos);
		/*--------------------------¿Cola vacia?------------------------------*/
		bool colaVacia();
		/*------------------Retorna el tamaño actual de la cola---------------*/
		int tamCola();
		/*-----------------------------Imprimir---------------------*/
		void imprimirCola(char pos);
};
template<typename T>
int cola<T>::tamCola(){
	return tam;
}
template<typename T>
bool cola<T>::colaVacia(){
	return (tam==0)?true:false;
}
template<typename T>
void cola<T>::enqueue(T inf,char pos){
	nodo<T> *nuevoNodo=new nodo<T>;
	nuevoNodo->info=inf;
	if(tam==0){
		nuevoNodo->ant=NULL;
		nuevoNodo->sig=NULL;
		frente=nuevoNodo;
		final=nuevoNodo;
		tam++;
	}else{
		switch(pos){
			case 'D':
				nuevoNodo->sig=frente;
				nuevoNodo->ant=NULL;
				frente->ant=nuevoNodo;
				frente=nuevoNodo;
				break;
			case 'I':
				nuevoNodo->sig=NULL;
				nuevoNodo->ant=final;
				final->sig=nuevoNodo;
				final=nuevoNodo;
				break;
		}
		tam++;
	}
}
template<typename T>
void cola<T>::dequeue(T &inf,char pos){
	if(tam==0){
		cout<<"No hay nada que eliminar"<<endl;
	}else{
		nodo<T> *aux;
		switch(pos){
			case 'I':
				inf=frente->info;
				aux=frente;
				frente=aux->sig;
				delete aux;
				tam--;
				break;
			case 'D':
				inf=final->info;
				aux=final;
				final=aux->ant;
				delete aux;
				tam--;
				break;
		}
	}
}
template<typename T>
void cola<T>::dequeue(char pos){
	if(tam==0){
		cout<<"No hay nada que eliminar"<<endl;
	}else{
		nodo<T> *aux;
		switch(pos){
			case 'I':
				aux=frente;
				frente=aux->sig;
				delete aux;
				tam--;
				break;
			case 'D':
				aux=final;
				final=aux->ant;
				delete aux;
				tam--;
				break;
			}
		}
}
template<typename T>
void cola<T>::imprimirCola(char pos){
	if(tam==0){
		cout<<"Cola vacia"<<endl;
	}else{
		nodo<T> *aux;
		switch(pos){
			case 'I':
			aux=frente;
			for(int i=0;i<tam;i++){
				if(aux->sig!=NULL){
					cout<<aux->info<<",";
				}else{
					cout<<aux->info;
				}
				aux=aux->sig;
			}
			break;
			case 'D':
			aux=final;
			for(int i=0;i<tam;i++){
				if(aux->ant!=NULL){
					cout<<aux->info<<",";
				}else{
					cout<<aux->info;
				}
				aux=aux->ant;
			}
		}
	}
	cout<<endl;
}
#endif
