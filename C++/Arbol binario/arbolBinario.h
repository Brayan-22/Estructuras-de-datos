#ifndef ARBOLBINARIOARRAY_H
#define ARBOLBINARIOARRAY_H
#include "Cola.h"
#include "Estructura.h"
#include <iostream>
#include "Pila.h"
using namespace std;
class arbolbinordArray{
	nodoArbol *arbol;
	/*
	cola<int> *inorden;
	cola<int> *posorden;
	cola<int> *preorden;
	cola<int> *niveles;
	nodoArbol *prueba;
	*/
	public:
		arbolbinordArray(int tamMax){
			arbol=new nodoArbol[tamMax+1];
			/*
			inorden= new cola<int>;
			posorden= new cola<int>;
			preorden= new cola<int>;
			niveles= new cola<int>;
			*/
			arbol[0].Hizq=0;
			arbol[0].Hder=1;
			for(int i=1;i<tamMax;i++){
				arbol[i].clave=0;
				arbol[i].Hizq=0;
				arbol[i].Hder=i+1;
			}
			arbol[tamMax].Hder=arbol[tamMax].Hizq=0;
		}
		~arbolbinordArray(){
			delete arbol;
		}
		bool insertar(int dato);
		bool eliminar(int dato);
		cola<int> inorden();
		cola<int> posorden();
		cola<int> preorden();
		cola<int> niveles();
		nodoArbol *getArray();
};
nodoArbol *arbolbinordArray::getArray(){
	return arbol;
}
bool arbolbinordArray::insertar(int dato){
	int libre=arbol[0].Hder;
	int raiz=arbol[0].Hizq;
	if(libre==0){
		cout<<"Arreglo lleno"<<endl;
		return false;
	}else if(raiz==0){
		arbol[libre].clave=dato;
		arbol[0].Hder=arbol[libre].Hder;
		arbol[0].Hizq=libre;
		arbol[libre].Hder=arbol[libre].Hizq=0;
		return true;
	}else{
		arbol[libre].clave=dato;
		arbol[0].Hder=arbol[libre].Hder;
		arbol[libre].Hder=arbol[libre].Hizq=0;
		while(raiz!=0){
			if(dato>arbol[raiz].clave){
				if(arbol[raiz].Hder==0){
					arbol[raiz].Hder=libre;
					raiz=0;
				}else{
					raiz=arbol[raiz].Hder;
				}
			}else{
				if(arbol[raiz].Hizq==0){
					arbol[raiz].Hizq=libre;
					raiz=0;
				}else{
					raiz=arbol[raiz].Hizq;
				}
			}
		}
		return true;
	}
}

bool arbolbinordArray::eliminar(int dato){
	int padre=arbol[0].Hizq;
	int hijo;
	bool encontrado=false;
	if(padre==0){
		cout<<"No hay nada que eliminar "<<endl;
		return false;
	}else if(arbol[padre].clave==dato){
			int Rpadre=arbol[padre].Hder;
			if(arbol[Rpadre].Hizq==0){
				arbol[Rpadre].Hizq=arbol[padre].Hizq;
				arbol[padre].Hizq=arbol[padre].clave=0;
				arbol[padre].Hder=arbol[0].Hder;
				arbol[0].Hder=padre;
				arbol[0].Hizq=Rpadre;
			}else{
				int Rhijo=arbol[Rpadre].Hizq;
				while(arbol[Rhijo].Hizq!=0){
					Rpadre=Rhijo;
					Rhijo=arbol[Rpadre].Hizq;
				}
				arbol[Rhijo].Hizq=arbol[padre].Hizq;
				arbol[Rhijo].Hder=arbol[padre].Hder;
				arbol[padre].clave=arbol[padre].Hizq=0;
				arbol[padre].Hder=arbol[0].Hder;
				arbol[0].Hizq=Rhijo;
				arbol[0].Hder=padre;
				arbol[Rpadre].Hizq=0;
			}
			return true;
		}else{
		while(encontrado!=true){
			if(dato<arbol[padre].clave){
				hijo=arbol[padre].Hizq;
				if(hijo==0 && arbol[hijo].clave!=dato){
					cout<<"Clave no encontrada"<<endl;
					return false;
					break;
				}else if(arbol[hijo].clave==dato){
					encontrado=true;
				}else{
					padre=hijo;
				}
			}else if(dato>arbol[padre].clave){
				hijo=arbol[padre].Hder;
				if(hijo==0 && arbol[hijo].clave!=dato){
					cout<<"Clave no encontrada"<<endl;
					return false;
					break;
				}else if(arbol[hijo].clave==dato){
					encontrado=true;
				}else{
					padre=hijo;
				}
			}
		}
		if(arbol[hijo].Hder==0 && arbol[hijo].Hizq==0){
			arbol[hijo].clave=0;
			if(arbol[padre].Hder==hijo){
				arbol[padre].Hder=0;
			}else{
				arbol[padre].Hizq=0;
			}
			arbol[hijo].Hder=arbol[0].Hder;
			arbol[0].Hder=hijo;
		}else if(arbol[hijo].Hder==0 && arbol[hijo].Hizq!=0){
			arbol[hijo].clave=0;
			if(arbol[padre].Hder==hijo){
				arbol[padre].Hder=arbol[hijo].Hizq;
			}else{
				arbol[padre].Hizq=arbol[hijo].Hizq;
			}
			arbol[hijo].Hizq=0;
			arbol[hijo].Hder=arbol[0].Hder;
			arbol[0].Hder=hijo;
			return true;
		}else if(arbol[hijo].Hder!=0 && arbol[hijo].Hizq==0){
			arbol[hijo].clave=0;
			if(arbol[padre].Hder==hijo){
				arbol[padre].Hder=arbol[hijo].Hder;
			}else{
				arbol[padre].Hizq=arbol[hijo].Hder;
			}
			arbol[hijo].Hizq=0;
			arbol[hijo].Hder=arbol[0].Hder;
			arbol[0].Hder=hijo;
			return true;
		}else{
			int Rpadre=arbol[hijo].Hder;
			if(arbol[Rpadre].Hizq==0){
				arbol[Rpadre].Hizq=arbol[hijo].Hizq;
				arbol[hijo].Hizq=0;
				arbol[hijo].Hder=arbol[0].Hder;
				arbol[0].Hder=hijo;
				if(arbol[padre].Hder==hijo){
					arbol[padre].Hder=Rpadre;
				}else{
					arbol[padre].Hizq=Rpadre;
				}
			}else{
				int Rhijo=arbol[Rpadre].Hizq;
				while(arbol[Rhijo].Hizq!=0){
					Rpadre=Rhijo;
					Rhijo=arbol[Rpadre].Hizq;
				}
				arbol[Rhijo].Hizq=arbol[hijo].Hizq;
				arbol[Rhijo].Hder=arbol[hijo].Hder;
				arbol[hijo].clave=arbol[hijo].Hizq=0;
				if(arbol[padre].Hder==hijo){
					arbol[padre].Hder=Rhijo;
				}else{
					arbol[padre].Hizq=Rhijo;
				}
				arbol[hijo].Hder=arbol[0].Hder;
				arbol[0].Hder=hijo;
				arbol[Rpadre].Hizq=0;
			}
		}
		return true;
	}
	
}

cola<int> arbolbinordArray::inorden(){
	pila<int> nuevaPila;
	cola<int> nuevaCola;
	int temp;
	int actual=arbol[0].Hizq;
	bool control=true;
	while(control){
		if(actual!=0){
			nuevaPila.insertar(actual);
			actual=arbol[actual].Hizq;
		}else if(actual==0 && nuevaPila.isEmpty()==false){
			nuevaPila.sacar(temp);
			nuevaCola.encolar(temp);
			actual=arbol[temp].Hder;
		}else{
			break;
		}
	}
	return nuevaCola;
}

#endif
