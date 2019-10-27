// https://codeforces.com/problemset/problem/1200/B
// @rohchakr
// https://codeforces.com/problemset/submission/1200/63488735

import java.util.Scanner;

public class Main {
  public static void main (String [] args) {
    Scanner s = new Scanner(System.in);
    int t = s.nextInt();
    while (t-- > 0) {
      int n = s.nextInt();
      int m = s.nextInt();
      int k = s.nextInt();
      int [] blocks = new int[n];
      for (int i = 0; i<n; i++) {
        blocks[i] = s.nextInt(); 
      } 
      int i = 0;
      for (i = 0; i<n-1; i++) {
      //  System.out.println("*****************" + m);
        if (blocks[i] + k >= blocks[i+1]) {
          // add blocks to bag and go
          int blocks_i = (0 >= blocks[i+1] - k) ? 0 : blocks[i+1] - k;
          if (blocks[i] > blocks[i+1]) { m += blocks[i] - blocks[i+1]; blocks[i] -= blocks[i] -  blocks[i+1]; }
          m += blocks[i] - blocks_i;
       //   System.out.println("++++++++++++++++" + m);
        } else if (m + k + blocks[i] >= blocks[i+1])  {
          // take out blocks from bag and go
          int blocks_i = blocks[i+1] - k;
          m -= blocks_i - blocks[i];
        //  System.out.println("---------------" + m);
        } else {
          // game over
          break;
        }
      }
        if (i == n-1) {
          System.out.println("YES");
        } else {
          System.out.println("NO");
        }
      
    }
  }
}
