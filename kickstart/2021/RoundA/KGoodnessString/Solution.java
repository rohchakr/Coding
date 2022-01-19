import java.util.*;

/**
 * goodness = find number of chars which are not equal to the corresponding chars from the end of the string
 * result = |goodness - target|
 */
public class Solution {
  public static void main(String[] args) {
    try (Scanner in = new Scanner(System.in)) {
      int cases = in.nextInt();
      int t;
      for (t = 1; t <= cases; t++) {
        int goodness = 0;
        int size = in.nextInt();
        int target = in.nextInt();
        String string = in.next();
        for (int i = 1; i <= size/2; i++) {
          if (string.charAt(i - 1) != string.charAt(size - i)) {
            goodness++;
          }
        }
        int result = Math.abs(goodness - target);
        System.out.println("Case #" + t + ": " + result);
      }
    }
  }
}