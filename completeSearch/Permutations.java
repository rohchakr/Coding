import java.util.Collections;
import java.util.List;
import java.util.LinkedList;
import java.util.ArrayList;

public class Permutations {
  public static void main(String[] args) {
    Integer[] a = {1, 2, 3};
    List<Integer> arr = new ArrayList<>();
    Collections.addAll(arr, a);
    boolean[] visited = new boolean[3]; // {false, false, false}
    Permutations s = new Permutations();
    List<Integer> permutation = new LinkedList<>(); // LinkedList because inserts and deletes are more than access
    List< List<Integer> > permutations = new LinkedList<>();
    s.generatePermutations(arr, permutations, permutation, visited);
    s.printPermutations(permutations);
  }

  private void generatePermutations(List<Integer> arr, List< List<Integer> > permutations, List<Integer> permutation, boolean[] visited) {
    // Base case
    if (permutation.size() == 3) {
      permutations.add(new LinkedList<Integer>(permutation));
      return;
    }

    for(int i = 0; i < 3; i++) {
      if (!visited[i]) {
        visited[i] = true;
        permutation.add(arr.get(i));
        generatePermutations(arr, permutations, permutation, visited);
        permutation.remove(arr.get(i));
        visited[i] = false;
      }
    }

    // Visualize using tree diagram
  }

  private void printPermutations(List< List<Integer> > permutations) {
    for(List<Integer> permutation : permutations) {
      System.out.println(permutation);
    }
  }
}

// Additional comments:
// Order doesn't matter - first include or exclude
