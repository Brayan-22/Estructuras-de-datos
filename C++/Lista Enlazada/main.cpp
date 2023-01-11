#include <iostream>
#include "listas.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	Lista<int> listaEnteros;
	Lista<float> listaFloat;
	Lista<char> listaChar;
	cout<<((listaEnteros.lista_vacia()==true)?"listaEnterosVacia":"La lista de enteros no esta vacia")<<endl;
	cout<<((listaFloat.lista_vacia()==true)?"listaFloatVacia":"La lista de float no esta vacia")<<endl;
	cout<<((listaEnteros.lista_vacia()==true)?"listaCHARVacia":"La lista de char no esta vacia")<<endl;
	int n;
	for(n=1;n<=10;n++){
		listaEnteros.insertar_final(n);
	}
	float m=0.5;
	for(int i=1;i<=15;i++){
		listaFloat.insertar_final(m);
		m++;
	}
	char a;
	for(int i=97;i<=122;i++){
		a=i;
		listaChar.insertar_final(a);
	}
	/*-------------------------LISTA INT---------------------------*/
	cout<<"El tamano de la listaEnteros es: "<<listaEnteros.tam_lista()<<endl;
	//eliminar el elemento de la posicion 9 de la lista, el numero 9
	listaEnteros.eliminar(9);
	cout<<listaEnteros.tam_lista()<<endl;
	//reestablecer el elemento eliminado anteriormente
	listaEnteros.insertar_pos(9,9);
	cout<<listaEnteros.tam_lista()<<endl;
	
	/*-------------------------LISTA FLOAT------------------------------------*/
	cout<<"El tamano de la listaFloat es: "<<listaFloat.tam_lista()<<endl;
	//eliminar el elemento de la posicion 9 de la lista, el numero 9.5
	listaFloat.eliminar(9);
	cout<<listaFloat.tam_lista()<<endl;
	//reestablecer el elemento eliminado anteriormente
	listaFloat.insertar_pos(9.5,9);
	cout<<listaFloat.tam_lista()<<endl;
	
	/*-------------------------LISTA CHAR-----------------------*/
	cout<<"El tamano de la listaChar es: "<<listaEnteros.tam_lista()<<endl;
	//eliminar el elemento de la posicion 9 de la lista, el caracter i
	listaChar.eliminar(9);
	cout<<listaChar.tam_lista()<<endl;
	//reestablecer el elemento eliminado anteriormente
	listaChar.insertar_pos('i',9);
	cout<<listaChar.tam_lista()<<endl;
	system("pause");
	return 0;
}
