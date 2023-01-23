package Data_Structures;
public class arbolAVL<T>{
    nodos.nodoArbolAVL<T> raiz;
    public arbolAVL(){
        this.raiz=null;
    }

    private nodos.nodoArbolAVL<T> buscar(int clave){
        nodos.nodoArbolAVL<T> actual=this.raiz;
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
    /* 
    private nodos.nodoArbolAVL<T> insertar(nodos.nodoArbolAVL<T> actual,int clave ,T info){
        if (actual==null) {
            nodos.nodoArbolAVL<T> nuevo=new nodos.nodoArbolAVL<T>(clave,info);
            return nuevo;
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
    */
    public boolean insertar(int clave,T info){
        nodos.nodoArbolAVL<T> nuevo = new nodos.nodoArbolAVL<T>(clave,info);
        nodos.nodoArbolAVL<T> actual =this.raiz;
        while (true) {
            @SuppressWarnings("unchecked") 
            nodos.nodoArbolAVL<T> aux =(nodos.nodoArbolAVL<T>)actual.clone();
            if (actual==null) {
                actual=nuevo;
                return true;
            }
            if (actual!=null) {
                if (clave<actual.clave) {
                    actual=aux.izq;
                }
            }
            if (actual!=null) {
                
            }
        }
    }
    
    public void insertar(int clave){
    }
    
    private void inOrden(nodos.nodoArbolAVL<T> actual){
        if (actual!=null) {
            inOrden(actual.izq);
            System.out.print(actual.clave + " ");
            inOrden(actual.der);
        }
    }
    
    private void preOrden(nodos.nodoArbolAVL<T> actual){
        if (actual!=null) {
            System.out.print(actual.clave + " ");
            preOrden(actual.izq);
            preOrden(actual.der);
        }
    }
    
    private void postOrden(nodos.nodoArbolAVL<T> actual){
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
        cola<nodos.nodoArbolAVL<T>> nuevaCola1 = new cola<>();
        cola<Integer> nuevaCola2 = new cola<>();
        nodos.nodoArbolAVL<T> actual=this.raiz;
        nodos.nodoArbolAVL<T> aux;
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
    
    private int altura(nodos.nodoArbolAVL<T> actual){
        if (actual == null){
            return 0;
        }else {
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
