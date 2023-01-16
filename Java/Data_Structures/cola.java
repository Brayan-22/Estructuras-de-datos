package Data_Structures;

public class cola<T> {
    private nodos.nodoSimple<T> cab;
    private int size;
    public cola(){
        this.cab=null;
        this.size=0;
    }
    public boolean push(T info){
        nodos.nodoSimple<T> nuevo=new nodos.nodoSimple<T>(info);
        if (this.cab==null) {
            this.cab=nuevo;
            this.size++;
            return true;
        }
        nodos.nodoSimple<T> aux=this.cab;
        while (!(aux.sig==null)) {
            aux=aux.sig;
        }
        aux.sig=nuevo;
        this.size++;
        return true;
    }
    public T pop(){
        T info=this.cab.info;
        this.cab=this.cab.sig;
        this.size--;
        return info;
    }
    public int size(){
        return this.size;
    }
    public boolean isEmpty(){
        return (this.size==0)?true:false;
    }
}
