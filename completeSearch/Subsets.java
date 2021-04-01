import java.util.List;
import java.util.LinkedList;

public class Subsets {
  public static void main(String args[]) {
    int n = 3;
    Subsets s = new Subsets();
    List<Integer> subset = new LinkedList<>(); // LinkedList because inserts and deletes are more than access
    List< List<Integer> > subsets = new LinkedList<>();
    s.generateSubsets(n, subsets, subset);
    s.printSubsets(subsets);
  }

  private void generateSubsets(int n, List< List<Integer> > subsets, List<Integer> subset) {
    // Base case
    if (n == 0) {
      subsets.add(new LinkedList<Integer>(subset));
      return;
    }

    // Step 1: Exclude n
    generateSubsets(n - 1, subsets, subset);

    // Step 2: Include n
    subset.add(n);
    generateSubsets(n - 1, subsets, subset);
    subset.remove(new Integer(n));
    
    // Visualize using tree diagram
  }

  private void printSubsets(List< List<Integer> > subsets) {
    for(List<Integer> subset : subsets) {
      System.out.println(subset);
    }
  }
}

// Additional comments:
// Order doesn't matter - first include or exclude
