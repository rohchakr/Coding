import java.util.Queue;
import java.util.LinkedList;

class Main {
  public static void main(String[] args) {
    //LinkedList<Integer> queue = new LinkedList<Integer>();
    Queue<Integer> queue = new LinkedList<Integer>();
    queue.add(2);
    queue.add(5);
    queue.add(7);
    System.out.println(queue);
    queue.remove();
    System.out.println(queue);
    //queue.addFirst(1); 
  }
}
