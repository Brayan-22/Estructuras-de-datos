#include <iostream>
#include <string.h>
#include "./HeaderFiles/ArbolAvl.h"
int main(int argc, char const *argv[])
{
    arbolAVL<string> *arbol = new arbolAVL<string>();
    arbol->insertar(100,"100");
    arbol->insertar(90,"90");
    arbol->insertar(80,"80");
    arbol->insertar(110,"110");
    arbol->insertar(95,"95");
    arbol->insertar(120,"120");
    arbol->insertar(130,"130");
    arbol->insertar(140,"140");
    arbol->insertar(111,"111");
    arbol->inOrden();
    arbol->eliminar(100);
    arbol->inOrden();
    arbol->insertar(128,"128");
    arbol->insertar(97,"97");
    arbol->insertar(85,"85");
    arbol->insertar(94,"94");
    arbol->insertar(72,"72");
    arbol->insertar(92,"92");
    arbol->insertar(76,"76");
    arbol->insertar(70,"70");
    arbol->insertar(81,"81");
    arbol->insertar(74,"74");
    arbol->eliminar(90);
    arbol->inOrden();
    arbol->eliminar(85);
    arbol->inOrden();
    arbol->eliminar(111);
    arbol->inOrden();
    system("pause");
    return 0;
}