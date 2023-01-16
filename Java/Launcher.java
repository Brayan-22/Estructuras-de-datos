import Data_Structures.pila;
import Data_Structures.cola;
public class Launcher{
    private pila<Integer> Stack;
    private cola<Integer> queue;
    public Launcher(){
        pruebaPila();
        pruebaCola();
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
    
    public static void main(String[] args) {
        new Launcher();
    }
}