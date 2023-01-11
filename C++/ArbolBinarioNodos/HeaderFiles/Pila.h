#ifndef PILA_H
#define PILA_H
#include<iostream>
using namespace std;
template<typename T>
struct nodoPila{
	T info;
	nodoPila<T> *sig;
};
template<typename T>
class pila{
	nodoPila<T> *frente;
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
	nodoPila<T> *nuevoNodo=new nodoPila<T>;
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
	nodoPila<T> *aux;
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
	nodoPila<T>*aux=frente;
	int i;
	for(i=0;i<getTam();i++){
		cout<<aux->info<<" ";
		aux=aux->sig;
	}
	cout<<endl;
}
#endif 
