import java.util.Stack;

public class Main {
  public static void main(String [] args) {
    Tree tree = new Tree(new Node(1));
    tree.populate();
    tree.dfs();
  }
}

class Tree {
  Node root;
  public Tree(Node root) { this.root = root; }
  public void populate() {
    root.leftChild = new Node(2); root.rightChild = new Node(3);
    root.leftChild.leftChild = new Node(4); root.leftChild.rightChild = new Node(5);
    root.rightChild.leftChild = new Node(6); root.rightChild.rightChild = new Node(7);
  }
  public void dfs() {
    Stack<Node> stack = new Stack<Node>();
    stack.push(root);
    while(!stack.empty()) {
      Node popped = stack.pop();
      if (popped.rightChild != null) { stack.push(popped.rightChild); }
      if (popped.leftChild != null) { stack.push(popped.leftChild); }
      System.out.print(popped.data + " ");
    }
    System.out.println();
  }
}

class Node {
  int data;
  Node leftChild;
  Node rightChild;
  public Node(int data) { this.data = data;leftChild=null;rightChild=null; }
}
