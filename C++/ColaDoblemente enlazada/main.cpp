/*
Brayan Alejandro Riveros Rodriguez 20201020084
David Cleves Guzman 20192020040
*/
#include <iostream>
#include "Cola.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	cola<int> Cola;
	cout<<((Cola.colaVacia()==true)?"cola vacia":"cola con elementos")<<endl;
	Cola.enqueue(3,'I'); // 3
	Cola.enqueue(8,'D'); // 8 3
	Cola.enqueue(10,'I'); // 8 3 10
	Cola.dequeue('D'); // 8 3
	Cola.enqueue(12,'D'); // 12 8 3
	Cola.dequeue('I'); // 8 3
	Cola.imprimirCola('I'); // 8 3
	system("pause");
}
