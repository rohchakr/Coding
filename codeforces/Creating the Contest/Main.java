// https://codeforces.com/problemset/problem/1029/B
// @rohchakr
// https://codeforces.com/problemset/submission/1029/63014977

import java.util.Scanner;
import java.lang.Math;

public class Main {
  public static void main(String [] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int first_num = s.nextInt();
    int second_num;
    int problems_count=1, max_problems_count=1;
    for (int i = 1; i<n; i++){
      second_num = s.nextInt();
      if (second_num <= 2*first_num) {
        problems_count ++;
        max_problems_count = Math.max(max_problems_count,problems_count);
      } else {
        problems_count = 1;
      }
      first_num = second_num;
    }
    System.out.println(max_problems_count);
  }
}
