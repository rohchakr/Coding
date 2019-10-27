// https://codeforces.com/problemset/problem/1016/A
// rohchakr
// https://codeforces.com/problemset/submission/1016/63554493

import java.util.Scanner;

public class Main {
  public static void main (String [] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int m = s.nextInt();
    int [] a = new int[n];
    for (int i = 0;i<n;i++) {
      a[i] = s.nextInt();
    }
    int lines_left = m;
    for (int i =0;i<n;i++) {
      int lines_current_page = lines_left - a[i];
      int pages_turned = 0;
      if (lines_current_page > 0) {
        lines_left = lines_current_page;
        System.out.print(pages_turned + " ");
      }
      else {
        int names_remaining = a[i] - lines_left;
        pages_turned ++;
        pages_turned += names_remaining / m;
        lines_left = m - names_remaining%m;
        System.out.print(pages_turned + " ");
      }
    }
  }
}
