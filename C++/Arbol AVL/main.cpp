#include<iostream>
#include "./HeaderFIles/Nodo.h"
#include "./HeaderFIles/Cola.h"
#include "./HeaderFIles/ArbolAvl.h"
using namespace std;

int main(int argc, char const *argv[])
{
    cola<int> nuevaCola;
    int user;
    arbolAvl *arbol = new arbolAvl;
    for (size_t i = 0; i < 8; i++)
    {
         std::cin>>user;
         std::cout<<std::endl;
         arbol->insertar(user);
    }
    arbol->inorden();
    arbol->preorden();
    arbol->postorden();
    arbol->niveles();
    return 0;
}