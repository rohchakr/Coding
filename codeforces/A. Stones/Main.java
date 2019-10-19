// https://codeforces.com/problemset/problem/1236/A
// https://codeforces.com/problemset/submission/1236/62939202
// 
// Solution:
// Considering two possibilities, 
// 1. Apply first operation upto max limit then apply second operation upto max limit 
// 2. Apply second operation upto max limit then apply first operation upto max limit
// All the cases are covered, no matter in which order the operations are performed
// Eg., Operation1, Operation2, Operation1 will give same result as Operation1, Operation1, Operation2

import java.util.Scanner;
import java.lang.Math;

public class Main {

  private static int approach1(int a, int b, int c) {
    int diff1, diff2;
// b/2 is the max limit for b, but if a is exhausted before this, then the limit will depend on a
    if (a-b/2 >= 0) {
      diff1 = b/2;
    } else {
      diff1 = a;
    }
    a = a - diff1;
    b = b - 2*diff1;
    
    if (b-c/2 >= 0) {
      diff2 = c/2;
    } else {
      diff2 = b;
    }
// stones collected for 1st operation = diff1 + 2*diff1 and 2nd operation = diff2 + 2*diff2
    return 3*(diff1 + diff2);
  }

private static int approach2(int a, int b, int c) {
    int diff1, diff2;
// b/2 is the max limit for b, but if a is exhausted before this, then the limit will depend on a
    if (b-c/2 >= 0) {
      diff1 = c/2;
    } else {
      diff1 = b;
    }
    b = b - diff1;
    c = c - 2*diff1;
    
    if (a-b/2 >= 0) {
      diff2 = b/2;
    } else {
      diff2 = a;
    }
// stones collected for 1st operation = diff1 + 2*diff1 and 2nd operation = diff2 + 2*diff2
    return 3*(diff1 + diff2);
  }

  public static void main (String [] args) {
    Scanner s = new Scanner(System.in);
    int t = s.nextInt();
    while (t-- > 0) {
      int a = s.nextInt();
      int b = s.nextInt();
      int c = s.nextInt();
      int result1 = approach1(a,b,c);
      int result2 = approach2(a,b,c);
      System.out.println(Math.max(result1, result2));
    }
  }
}
