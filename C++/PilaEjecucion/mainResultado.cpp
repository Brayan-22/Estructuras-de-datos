#include <iostream>
#include "libreriaPila.h"

using namespace std;
int main(int argc, char** argv) {
	char c;
	Pila<int> acc(50);
	int x;
	while(cin.get(c)&&c!='\n'){
		x=0;
		while(c==' ')cin.get(c);
		while(c>='0'&&c<='9'){
			x=10*x + (c-'0');
			cin.get(c);
		}
		if(c=='+')x=acc.pop()+acc.pop();
		if(c=='*')x=acc.pop()*acc.pop();
		acc.push(x);
	}
	cout<<"Resultado: "<<acc.pop()<<'\n';
}
