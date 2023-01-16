import Data_Structures.pila;

public class Launcher{
    private pila<Integer> Stack;
    public Launcher(){
        pruebaPila();
    }
    private void pruebaPila(){
        this.Stack = new pila<Integer>();
        for (int i = 0; i <= 12; i++) {
            Stack.push(i);
        }
        int tam=Stack.size();
        for (int i = 0; i < tam; i++) {
            System.out.println(Stack.pop());  
        }
        System.out.println((Stack.isEmpty())?"VACIA":"NO VACIA");
    }
    public static void main(String[] args) {
        new Launcher();
    }
}