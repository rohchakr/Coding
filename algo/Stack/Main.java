// Implement Stack
// rohchakr

import java.util.Stack;
public class Main {
  public static void main (String[] args) {
    Stack<Integer> stack1 = new Stack<Integer>();
    stack1.push(2);
    stack1.push(5);
    stack1.push(2); // search will give first occurence
    stack1.add(3); // same as push
    printStackMethod(stack1);
    printStackMethod(new Stack<Integer>());
  }
  private static void printStackMethod(Stack<Integer> stack) {
    System.out.print(stack.empty() + " ");
    System.out.print(stack.size() + " ");
    if (!stack.empty()) {
      System.out.print(stack.peek() + " ");
      int popped = stack.pop();
      System.out.print(popped + " ");
      stack.push(popped);
    }
    System.out.print(stack.search(2));
    System.out.println();
  }
}


