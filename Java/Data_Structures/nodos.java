package Data_Structures;

public class nodos{
    public static class nodoSimple<T>{
        public T info;
        public nodoSimple<T> sig;
        public nodoSimple(T info){
            this.info=info;
            this.sig=null;
        }
        public nodoSimple(){
            this.info=null;
            this.sig=null;
        }
    }
    public static class nodoArbolBin<T>{
        public int clave;
        public T info;
        public nodoArbolBin<T> izq;
        public nodoArbolBin<T> der;
        public nodoArbolBin(int clave,T info){
            this.clave=clave;
            this.info=info;
            this.izq=null;
            this.der=null;
        }
        public nodoArbolBin(int clave){
            this.clave=clave;
            this.info=null;
            this.izq=null;
            this.der=null;
        }
        public nodoArbolBin(){
            this.info=null;
            this.izq=null;
            this.der=null;
        }
    }
}