#include <iostream>
#include "libreriaPila.h"

using namespace std;
int main(int argc, char** argv) {
	/*------------------------------------------------*/
	char c;
	Pila<char> guardar(50);
	cout<<"Digite una operacion aritmetica con '()' '*' '+'"<<endl;
	while(cin.get(c) && c!='\n'){
		while(c>='0' && c<='9'){cout.put(c);cin.get(c);}
		if(c==')'){cout<<' ';cout.put(guardar.pop());}
		if(c=='+')guardar.push(c);
		if(c=='*')guardar.push(c);
		if(c!='(')cout<<' ';
	}
	cout<<'\n';
	system("pause");
	return 0;
}
