// https://codeforces.com/problemset/problem/1139/B
// rohchakr
// https://codeforces.com/problemset/submission/1139/63562274

import java.util.Scanner;

public class Main {
  public static void main (String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt() ;
    int [] a = new int[n];
    for (int i = 0; i<n ; i++)
      a[i] = s.nextInt();
    long chocolates = a[n-1];
    for (int i = n-2; i>=0 ; i--)
    {
      int pick = 0;
      if (a[i] < a[i+1]) pick = a[i];
      else { pick = a[i+1] - 1; a[i] = pick; }
      if (pick <=0) break;
      chocolates += pick;
    }
    System.out.println(chocolates);
  }
}
