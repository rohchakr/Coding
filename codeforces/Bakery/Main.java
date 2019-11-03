// https://codeforces.com/problemset/problem/707/B
// rohchakr
// https://codeforces.com/contest/707/submission/64144015

import java.util.Scanner;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.HashSet;

public class Main {
  public static void main(String [] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int m = s.nextInt();
    int k = s.nextInt();
    ArrayList<ArrayList<Integer> > edgeList = new ArrayList<ArrayList<Integer> >(m+1);
    for (int i = 0 ; i <= m ; i++ )
      edgeList.add(new ArrayList<Integer>());
    for (int i = 1;i <= m; i ++) {
      edgeList.get(i).add(s.nextInt());
      edgeList.get(i).add(s.nextInt());
      edgeList.get(i).add(s.nextInt());
    }
    HashSet<Integer> flour_storage = new HashSet<Integer>(k+1);
    for (int i = 1; i<=k; i++)
      flour_storage.add(s.nextInt());
    //System.out.println(edgeList.toString());
    //System.out.println(flour_storage.toString());
    int cost = -1;
    for (int i = 1; i<=m; i++) {
      if (( flour_storage.contains(edgeList.get(i).get(0)) && !flour_storage.contains(edgeList.get(i).get(1))) ||
          ( !flour_storage.contains(edgeList.get(i).get(0)) && flour_storage.contains(edgeList.get(i).get(1)))) {
        if (cost == -1 || cost > edgeList.get(i).get(2)) cost = edgeList.get(i).get(2);
      }
    }
    System.out.println(cost);
  }
}
