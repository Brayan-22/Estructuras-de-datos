#include <iostream>
#include "./HeaderFiles/ArbolBinario.h"
int main(int argc, char const *argv[])
{
    arbolBin *arbol = new arbolBin;
    arbol->insertar(120);
    arbol->insertar(87);
    arbol->insertar(140);
    arbol->insertar(43);
    arbol->insertar(99);
    arbol->insertar(130);
    arbol->insertar(22);
    arbol->insertar(65);
    arbol->insertar(93);
    arbol->insertar(135);
    arbol->insertar(56);
    arbol->insertar(100);
    arbol->insertar(95);
    arbol->insertar(180);
    arbol->insertar(170);
    arbol->insertar(175);
    arbol->insertar(200);
    return 0;
}
