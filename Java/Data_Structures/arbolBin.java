package Data_Structures;
public class arbolBin<T> {
    nodos.nodoArbolBin<T> raiz;
    public arbolBin(){
        this.raiz=null;
    }

    public boolean busqueda(int clave){
        nodos.nodoArbolBin<T> actual=this.raiz;
        while (true) {
            if (actual==null) {
                return false;
            }
            if (actual.clave==clave) {
                return true;
            }
            if (actual!=null) {
                if (clave<actual.clave) {
                    actual=actual.izq;
                }
            }
            if (actual!=null) {
                if (clave>actual.clave) {
                    actual=actual.der;
                }
            }
        }
    }

    public T getInfo(int clave){
        nodos.nodoArbolBin<T> actual=buscar(clave);
        return (actual!=null)?actual.info:null;
    }

    public boolean isEmpty(){
        return (this.raiz==null)?true:false;
    }

    private nodos.nodoArbolBin<T> buscar(int clave){
        nodos.nodoArbolBin<T> actual=this.raiz;
        while (true) {
            if (actual==null) {
                return null;
            }
            if (actual.clave==clave) {
                return actual;
            }
            if (actual!=null) {
                if (clave<actual.clave) {
                    actual=actual.izq;
                }
            }
            if (actual!=null) {
                if (clave>actual.clave) {
                    actual=actual.der;
                }
            }
        }
    }

    private nodos.nodoArbolBin<T> buscarPadre(nodos.nodoArbolBin<T> hijo){
        if (hijo==this.raiz) return null;
        nodos.nodoArbolBin<T> padre=this.raiz;
        while (true) {
            if (padre==null)return null;
            if (hijo.clave<padre.clave) {
                if ((padre.der==hijo)||(padre.izq==hijo))return padre;
                padre=padre.izq;
            }
            if (hijo.clave>padre.clave) {
                if ((padre.der==hijo)||(padre.izq==hijo))return padre;
                padre=padre.der;
            }
        }
    }

    private nodos.nodoArbolBin<T> insertar(nodos.nodoArbolBin<T> actual,int clave ,T info){
        if (actual==null) {
            return new nodos.nodoArbolBin<T>(clave, info);
        }
        if (clave<actual.clave) {
            actual.izq=insertar(actual.izq, clave, info);
        }else if (clave>=actual.clave) {
            actual.der=insertar(actual.der, clave, info);
        }else{
            return actual;
        }
        return actual;
    }
    
    public void insertar(int clave,T info){
        this.raiz=insertar(this.raiz, clave, info);
    }
    
    public void insertar(int clave){
        this.raiz=insertar(this.raiz, clave, null);
    }
    
    public boolean eliminar(int clave){
        nodos.nodoArbolBin<T> actual=buscar(clave);
        if (actual==null) {
            return false;
        }
        if (actual==this.raiz) {
            if (actual.der==null && actual.izq==null) {
                actual=null;
                return true;
            }
            if (actual.der==null && actual.izq!=null) {
                actual=actual.izq;
                return true;
            }
            if (actual.der!=null && actual.izq==null) {
                actual=actual.der;
                return true;
            }
            nodos.nodoArbolBin<T> aux=actual;
            nodos.nodoArbolBin<T> temp=actual.der;
            while (true) {
                if (temp.izq==null) {
                    aux.izq=temp.der;
                    temp.izq=actual.izq;
                    temp.der=actual.der;
                    this.raiz=temp;
                    return true;
                }
                aux=temp;
                temp=aux.izq;
            }
        }else{
            nodos.nodoArbolBin<T> padre = buscarPadre(actual);
            if (padre.der==actual) {
                if (actual.der==null && actual.izq==null) {
                    padre.der=null;
                    return true;
                }
                if (actual.der==null && actual.izq!=null) {
                    padre.der=actual.izq;
                    return true;
                }
                if (actual.der!=null && actual.izq==null) {
                    padre.der=actual.der;
                    return true;
                }
                if (actual.der!=null && actual.izq!=null) {
                    nodos.nodoArbolBin<T> aux=actual;
                    nodos.nodoArbolBin<T> temp=actual.der;
                    while (true) {
                        if (temp.izq==null) {
                            aux.izq=temp.der;
                            temp.izq=actual.izq;
                            temp.der=actual.der;
                            padre.der=temp;
                            return true;
                        }
                        aux=temp;
                        temp=aux.izq;
                    }
                }
            }
            if (padre.izq==actual) {
                if (actual.der==null && actual.izq==null) {
                    padre.izq=null;
                    return true;
                }
                if (actual.der==null && actual.izq!=null) {
                    padre.izq=actual.izq;
                    return true;
                }
                if (actual.der!=null && actual.izq==null) {
                    padre.izq=actual.der;
                    return true;
                }
                if (actual.der!=null && actual.izq!=null) {
                    nodos.nodoArbolBin<T> aux=actual;
                    nodos.nodoArbolBin<T> temp=actual.der;
                    while (true) {
                        if (temp.izq==null) {
                            aux.izq=temp.der;
                            temp.izq=actual.izq;
                            temp.der=actual.der;
                            padre.izq=temp;
                            return true;
                        }
                        aux=temp;
                        temp=aux.izq;
                    }
                }
            }
        }
        return false;
    }

    private void inOrden(nodos.nodoArbolBin<T> actual){
        if (actual!=null) {
            inOrden(actual.izq);
            System.out.print(actual.clave + " ");
            inOrden(actual.der);
        }
    }
    
    private void preOrden(nodos.nodoArbolBin<T> actual){
        if (actual!=null) {
            System.out.print(actual.clave + " ");
            preOrden(actual.izq);
            preOrden(actual.der);
        }
    }
    
    private void postOrden(nodos.nodoArbolBin<T> actual){
        if (actual != null) {
            postOrden(actual.izq);
            postOrden(actual.der);
            System.out.print(actual.clave + " ");
        }
    }

    public void inOrden(){
        if (this.raiz == null) {
            System.out.println("Arbol vacio");
        }
        inOrden(this.raiz);
        System.out.println();
    }
    
    public void preOrden(){
        if (this.raiz == null) {
            System.out.print("Arbol vacio");
        }
        preOrden(this.raiz);
        System.out.println();
    }

    public void postOrden(){
        if (this.raiz == null) {
            System.out.print("Arbol vacio");
        }
        postOrden(this.raiz);
        System.out.println();
    }

    public void recorridoNiveles(){
        cola<nodos.nodoArbolBin<T>> nuevaCola1 = new cola<>();
        cola<Integer> nuevaCola2 = new cola<>();
        nodos.nodoArbolBin<T> actual=this.raiz;
        nodos.nodoArbolBin<T> aux;
        int temp;
        nuevaCola1.push(actual);
        while (!nuevaCola1.isEmpty()) {
            aux=nuevaCola1.pop();
            temp=aux.clave;
            nuevaCola2.push(temp);
            if (aux.izq!=null)nuevaCola1.push(aux.izq);
            if (aux.der!=null)nuevaCola1.push(aux.der);
        }
        int count = nuevaCola2.size();
        for (int i = 0; i < count; i++) {
            System.out.print(nuevaCola2.pop() + " ");
        }
        System.out.println();
    }
    
    /*Funciones utiles */
    /* Calcular la "altura" de un árbol 
    -- el número de nodos a lo largo del camino más largo desde el nodo raíz hasta el nodo hoja más lejano.
    */
    private int altura(nodos.nodoArbolBin<T> actual)
    {
        if (actual == null)
            return 0;
        else {
            /* calcular la altura de cada subarbol*/
            int izqAltura = altura(actual.izq);
            int derAltura = altura(actual.der);
 
            /* retornar el mas "alto" */
            return (izqAltura > derAltura)?(izqAltura + 1):(derAltura + 1);
        }
    }

    public int altura(){
        return altura(this.raiz);
    }
}