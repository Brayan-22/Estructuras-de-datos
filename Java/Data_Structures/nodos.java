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
    public static class nodoArbolAVL<T> implements Cloneable{
        public int clave;
        private int fb;//-->factor de balance
        public T info;
        public nodoArbolAVL<T> izq;
        public nodoArbolAVL<T> der;
        public nodoArbolAVL(int clave,T info){
            this.clave=clave;
            this.info=info;
            this.izq=null;
            this.der=null;
        }
        public nodoArbolAVL(int clave){
            this.clave=clave;
            this.info=null;
            this.izq=null;
            this.der=null;
        }
        public nodoArbolAVL(){
            this.info=null;
            this.izq=null;
            this.der=null;
        }
        
        public int getFb(){
            if (this.der==null && this.izq!=null) {
                fb=(0-this.izq.altura());
            }
            else if (this.der!=null && this.izq==null) {
                fb=(this.der.altura()-0);
            }
            else if (this.der==null && this.izq==null) {
                fb=0;
            }else{
                fb=(this.der.altura()-this.izq.altura());
            }
            return this.fb;
        }

        private int altura(nodoArbolAVL<T> actual){
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
            return altura(this);
        }

        public Object clone(){
            Object obj=null;
            try {
                obj=super.clone();
            } catch (CloneNotSupportedException  e) {
                System.out.println("No se puede duplicar");
            }
            return obj;
        }
    }
}