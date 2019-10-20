// https://codeforces.com/problemset/problem/580/A
// @rohchakr
// https://codeforces.com/problemset/submission/580/62967147

import java.util.Scanner;

public class Main {
  public static void main (String [] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int [] a = new int [n];
    int longest_sequence_size = 1, sequence_size = 1;
    for (int i = 0; i<n; i++) {
      a[i] = s.nextInt(); 
    }
    if (n == 1) {
      System.out.println(1);
      return;
    }   

    for (int i = 1;i<n;i++) {
      if( a[i] >= a[i-1] ) {
        sequence_size++;
        longest_sequence_size = (longest_sequence_size > sequence_size)?longest_sequence_size:sequence_size;
      } else {
        sequence_size = 1;
      }
    }

    System.out.println(longest_sequence_size);
  }
}
