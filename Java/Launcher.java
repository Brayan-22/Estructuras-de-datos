import Data_Structures.pila;
import Data_Structures.cola;
import Data_Structures.arbolBin;
public class Launcher{
    private pila<Integer> Stack;
    private cola<Integer> queue;
    private arbolBin<String> tree;
    public Launcher(){
        //pruebaPila();
        //pruebaCola();
        pruebaTree();
    }
    private void pruebaPila(){
        System.out.println("PILA:");  
        this.Stack = new pila<Integer>();
        for (int i = 0; i <= 12; i++) {
            Stack.push(i);
        }
        int tam=Stack.size();
        for (int i = 0; i < tam; i++) {
            System.out.print(Stack.pop()+",");  
        }
        System.out.println();  
        System.out.println((Stack.isEmpty())?"VACIA":"NO VACIA");
    }
    
    private void pruebaCola(){
        System.out.println("COLA:");  
        this.queue = new cola<Integer>();
        for (int i = 0; i <= 12; i++) {
            queue.push(i);
        }
        int tam=queue.size();
        for (int i = 0; i < tam; i++) {
            System.out.print(queue.pop()+",");  
        }
        System.out.println();  
        System.out.println((queue.isEmpty())?"VACIA":"NO VACIA");
    }

    private void pruebaTree(){
        System.out.println("ARBOL BINARIO: ");
        tree = new arbolBin<String>();
        tree.insertar(120, "INFO 120");
        tree.insertar(87, "INFO 87");
        tree.insertar(140,"INFO 140");
        tree.insertar(43,"INFO 43");
        tree.insertar(99,"INFO 99");
        tree.insertar(130,"INFO 130");
        tree.insertar(22,"INFO 22");
        tree.insertar(65,"INFO 65");
        tree.insertar(93,"INFO 93");
        tree.insertar(135,"INFO 135");
        tree.insertar(56,"INFO 56");
        tree.insertar(100,"INFO 100");
        tree.insertar(95,"INFO 95");
        tree.insertar(180,"INFO 180");
        tree.insertar(170,"INFO 170");
        tree.insertar(175,"INFO 175");
        tree.insertar(200,"INFO 200");
        //ARBOL RESULTANTE: 
        /*
                                            120
                                         /       \
                                       87         140
                                      /  \       /    \
                                    43    99   130     180
                                   / \    / \     \    /  \
                                 22  65  93 100   135 170  200
                                    /      \             \          
                                   56      95            175
         */
        System.out.println("Recorrido inOrden: ");tree.inOrden();
        System.out.println("Recorrido preOrden: ");tree.preOrden();
        System.out.println("Recorrido postOrden: ");tree.postOrden();
        System.out.println("Recorrido por niveles: ");tree.recorridoNiveles();
        System.out.println("56 "+(tree.busqueda(56)?"Encontrado":"No encontrado"));
        System.out.println("300 "+(tree.busqueda(300)?"Encontrado":"No encontrado"));
        //CASO 1 ELIMINACION: El nodo a eliminar no tiene hijos
        tree.eliminar(175);
        //CASO 2 ELIMINACION: El nodo a eliminar tiene un solo hijo
        tree.eliminar(93);
        tree.eliminar(65);
        //ARBOL RESULTANTE: 
        /*
                                            120
                                         /       \
                                       87         140
                                      /  \       /    \
                                    43    99   130     180
                                   / \    / \     \    /  \
                                 22  56  95 100   135 170  200
         */
        //CASO 3 ELIMINACION: El nodo a eliminar tiene dos hijos->Se reemplaza por el nodo de la "derecha mas a la izquierda"
        System.out.println("Recorrido inOrden: ");tree.inOrden();
        tree.eliminar(87);
        //ARBOL RESULTANTE: 
        /*
                                            120
                                         /       \
                                       95         140
                                      /  \       /    \
                                    43    99   130     180
                                   / \      \     \    /  \
                                 22  56     100   135 170  200
         */
        System.out.println("Recorrido inOrden: ");tree.inOrden();
        tree.eliminar(120);
        //ARBOL RESULTANTE: 
        /*
                                            130
                                         /       \
                                       95         140
                                      /  \       /    \
                                    43    99   135     180
                                   / \      \          /  \
                                 22  56     100      170  200
         */
        System.out.println("Recorrido inOrden: ");tree.inOrden();
        System.out.println(tree.getInfo(200));
    }
    public static void main(String[] args) {
        new Launcher();
    }
}