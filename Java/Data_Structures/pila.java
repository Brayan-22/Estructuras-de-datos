package Data_Structures;
public class pila<T> {
    private nodos.nodoSimple<T> cab;
    private int size;
    public pila(){
        this.size=0;
        this.cab=null;
    }
    public boolean push(T info){
        nodos.nodoSimple<T> nuevo=new nodos.nodoSimple<T>(info);
        if (this.cab==null) {
            this.cab=nuevo;
            this.size++;
            return true;
        }
        nuevo.sig=this.cab;
        this.cab=nuevo;
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
