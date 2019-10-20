// https://codeforces.com/problemset/problem/910/A
// @rohchakr
// https://codeforces.com/problemset/submission/910/62972687

import java.util.Scanner;

public class Main {
  public static void main(String [] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int d = s.nextInt();
    String str = s.next();
    int jumpPos = 1 + d;
    int jumpsCount = 0;
    int currentPos = 1;
    int output;
    while(currentPos < jumpPos && currentPos < n) {
      if(jumpPos > n) jumpPos = n;
      if('1' == str.charAt(jumpPos-1)) {
        jumpsCount ++;
        currentPos = jumpPos;
        jumpPos += d;
      }
      else
        jumpPos --;
    }
    if (currentPos == jumpPos)
      output = -1;
    else if (currentPos == n)
      output = jumpsCount;
    else 
      output = -2; // this should never be the case
    System.out.println(output);
  }
}
