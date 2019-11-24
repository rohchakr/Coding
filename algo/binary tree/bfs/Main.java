//             1
//            / \
//           /   \
//          /     \
//         /       \
//        /         \
//       /           \
//      2             3
//     / \           /  \
//    /   \         /    \
//   4     5       6      7
//  / \   / \     / \    / \
// 8  9 10  11  12  13  14  15

import java.util.Queue;
import java.util.LinkedList;

class Node {
  int data;
  Node leftChild;
  Node rightChild;
  Node(int data) {
    this.data = data;
  }
}
class Tree {
  public Node populateTree(Node root) {
    root.leftChild = new Node(2); root.rightChild = new Node(3);
    root.leftChild.leftChild = new Node(4); root.leftChild.rightChild = new Node(5);
    root.rightChild.leftChild = new Node(6); root.rightChild.rightChild = new Node(7);
    root.leftChild.leftChild.leftChild = new Node(8); root.leftChild.leftChild.rightChild = new Node(9);
    root.leftChild.rightChild.leftChild = new Node(10); root.leftChild.rightChild.rightChild = new Node(11);
    root.rightChild.leftChild.leftChild = new Node(12); root.rightChild.leftChild.rightChild = new Node(13);
    root.rightChild.rightChild.leftChild = new Node(14); root.rightChild.rightChild.rightChild = new Node(15);
    return root;
  }
  public void bfs(Node root) {
    Queue<Node> q = new LinkedList<Node>();
    Node n = root;
    q.add(root);
    while (q.peek() != null) {
      Node removed = q.remove();
      System.out.print(removed.data + " ");
      if (n.leftChild != null) q.add(n.leftChild);
      if (n.rightChild != null) q.add(n.rightChild);
      n = q.peek();
    }
    System.out.println();
  }
}
class Main {
  public static void main(String[] args) {
    Tree tree = new Tree();
    Node root = tree.populateTree(new Node());
    tree.bfs(root);
  }
}
