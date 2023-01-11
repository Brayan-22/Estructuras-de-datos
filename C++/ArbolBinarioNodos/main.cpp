#include <iostream>
#include "./HeaderFiles/ArbolBinario.h"
#include "./HeaderFiles/Nodo.h"
int main(int argc, char const *argv[])
{
    arbolBin *arbol = new arbolBin;
    std::cout<<"INSERCIONES:"<<std::endl;
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
    std::cout<<"RECORRIDOS:"<<std::endl;
    std::cout<<"INORDEN:"<<std::endl;
    arbol->inorden();
    std::cout<<"PREORDEN:"<<std::endl;
    arbol->preorden();
    std::cout<<"POSTORDEN:"<<std::endl;
    arbol->postorden();
    std::cout<<"NIVELES:"<<std::endl;
    arbol->niveles();
    std::cout<<"BUSQUEDA:"<<std::endl;
    arbol->busqueda(120);
    arbol->busqueda(175);
    arbol->busqueda(500);
    std::cout<<"ELIMINACION:"<<std::endl;
    arbol->eliminar(95);//PRIMER CASO
    arbol->inorden();
    arbol->eliminar(65);//SEGUNDO CASO
    arbol->inorden();
    arbol->eliminar(87);//TERCER CASO
    arbol->inorden();
    arbol->eliminar(500);//CASO NODO NO EXISTE
    return 0;
}