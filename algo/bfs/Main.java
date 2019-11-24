import java.util.Queue;
import java.util.LinkedList;

class Node {
  int data;
  Node leftChild;
  Node rightChild;
  public Node(int data) {this.data = data;leftChild=null;rightChild=null;}
}
class Tree {
  Node root;
  public Tree(Node root) { this.root = root; }
  public void populate() {
    root.leftChild = new Node(2); root.rightChild = new Node(3);
    root.leftChild.leftChild = new Node(4); root.leftChild.rightChild = new Node(5);
    root.rightChild.leftChild = new Node(6); root.rightChild.rightChild = new Node(7);
  }
  public void bfs() {
    Queue<Node> queue = new LinkedList<Node>();
    queue.add(root);
    while (!queue.isEmpty()) {
      Node removed = queue.remove();
      System.out.print(removed.data + " ");
      if(removed.leftChild!=null) queue.add(removed.leftChild);
      if(removed.rightChild!=null) queue.add(removed.rightChild);
    }
    System.out.println();
  }
}
class Main{
  public static void main(String[] args) {
    Tree tree = new Tree(new Node(1));
    tree.bfs();
    tree.populate();
    tree.bfs();
  }
}
