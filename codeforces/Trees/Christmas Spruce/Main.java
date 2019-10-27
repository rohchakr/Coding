// https://codeforces.com/problemset/problem/913/B
// rohchakr
// https://codeforces.com/problemset/submission/913/63608429

import java.util.Scanner;

public class Main {
  public static void main (String [] args) {
    Scanner s = new Scanner (System.in);
    int n = s.nextInt();
    int [] parent = new int[n+1];
    for (int i =2; i<=n; i++) 
      parent[i] = s.nextInt();
    boolean [] isleaf = new boolean[n+1];
    for (int i =1; i<=n; i++)
      isleaf[i] = true;
    int [] leafChildrenCount = new int[n+1];
    for (int i =1; i<=n; i++)
      leafChildrenCount[i] = 0;

    // populate isleaf
    for (int i =2; i<=n; i++)
      isleaf[parent[i]] = false;

    // count leaf children
    for (int i =2; i<=n; i++)
      if (isleaf[i]) leafChildrenCount[parent[i]]++;

    boolean spruce = true;
    for(int i =1; i<=n; i++)
      if(isleaf[i] == false && leafChildrenCount[i] < 3) { spruce = false; break; }

    //for (int i =0;i<n+1;i++) System.out.println(isleaf[i]);
    //for (int i = 0; i<n+1; i++ ) System.out.println(leafChildrenCount[i]);
    System.out.println((spruce == true)?"Yes":"No");
  }
}
