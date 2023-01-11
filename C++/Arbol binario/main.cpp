#include <iostream>
#include "arbolBinario.h"
#include "Estructura.h"
#include "Pila.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	arbolbinordArray arbol(13);
	nodoArbol *array=arbol.getArray();
	cout<<"Arreglo vacio:"<<endl;
	for(int i=0;i<14;i++){
		if(i>0){
			cout<<array[i].clave<<" "<<array[i].Hizq<<" "<<array[i].Hder<<"|";
		}else{
			cout<<array[i].Hizq<<" "<<array[i].Hder<<"|";
		}
	}
	cout<<endl;
	arbol.insertar(100);
	arbol.insertar(150);
	arbol.insertar(50);
	arbol.insertar(30);
	arbol.insertar(75);
	arbol.insertar(125);
	arbol.insertar(170);
	arbol.insertar(10);
	arbol.insertar(60);
	arbol.insertar(90);
	arbol.insertar(180);
	arbol.insertar(140);
	arbol.insertar(160);
	cout<<"Arreglo lleno:"<<endl;
	for(int i=0;i<14;i++){
		if(i>0){
			cout<<array[i].clave<<" "<<array[i].Hizq<<" "<<array[i].Hder<<"|";
		}else{
			cout<<array[i].Hizq<<" "<<array[i].Hder<<"|";
		}
	}
	cout<<endl;
	//********Descomentar para verificar funcionamiento*******
	//arbol.eliminar(10);
	cout<<"Eliminado clave 10:"<<endl;
	for(int i=0;i<14;i++){
		if(i>0){
			cout<<array[i].clave<<" "<<array[i].Hizq<<" "<<array[i].Hder<<"|";
		}else{
			cout<<array[i].Hizq<<" "<<array[i].Hder<<"|";
		}
	}
	cout<<endl;
	//arbol.eliminar(125);
	cout<<"Eliminado clave 125:"<<endl;
	for(int i=0;i<14;i++){
		if(i>0){
			cout<<array[i].clave<<" "<<array[i].Hizq<<" "<<array[i].Hder<<"|";
		}else{
			cout<<array[i].Hizq<<" "<<array[i].Hder<<"|";
		}
	}
	cout<<endl;
	//arbol.eliminar(50);
	cout<<"Eliminado clave 50:"<<endl;
	for(int i=0;i<14;i++){
		if(i>0){
			cout<<array[i].clave<<" "<<array[i].Hizq<<" "<<array[i].Hder<<"|";
		}else{
			cout<<array[i].Hizq<<" "<<array[i].Hder<<"|";
		}
	}
	cout<<endl;
	int n;
	cola<int> Cola=arbol.inorden();
	cout<<"Recorrido inorden:"<<endl;
	while(Cola.isEmpty()==false){
		Cola.desencolar(n);
		cout<<array[n].clave<<" ";
	}
	cout<<endl;

}

