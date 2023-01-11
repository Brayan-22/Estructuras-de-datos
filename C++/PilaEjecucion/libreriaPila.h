#ifndef PILA_H
#define PILA_H

template<typename T>
class Pila{
	T *pila;
	int p;
	public:
		Pila(int max=100){
			pila = new T[max];
			p=0;
		}
		~Pila(){delete pila;}
		inline void push(T v){pila[p++]=v;}
		inline T pop(){return pila[--p];}
		inline int vacia(){return !p;}
};
#endif
