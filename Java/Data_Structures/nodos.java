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
}