// https://codeforces.com/problemset/problem/115/A
// rohchakr
// https://codeforces.com/problemset/submission/115/64108666

import java.util.Scanner;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.ArrayDeque;

public class Main {
  public static void main (String [] args) {
    Scanner s = new Scanner (System.in);
    int n = s.nextInt();
    int [] p = new int[n+1];
    for (int i = 1; i<=n; i++)
      p[i] = s.nextInt();
    
    // all p[i] with -1 can be considered as roots,
    // need to find the max length from any root to its leaves    
    ArrayList<LinkedList<Integer> > adjacencyList = new ArrayList<LinkedList<Integer> >(n+1);
    for (int i = 0; i<=n; i++) {
      adjacencyList.add(i,new LinkedList<Integer>());
    }
    for (int i = 1; i<=n; i++) {
      if(p[i] != -1)
        adjacencyList.get(p[i]).add(i);
    }
    //System.out.println(adjacencyList.toString());
   
    // bfs for all i whose p[i] = -1
    int maxReportsAll = 0;
    for (int i = 1; i <= n; i++) {
      if(p[i] == -1) {
        int maxReports = getMaxReports(i,adjacencyList);
        //System.out.println("MaxReports-" + i + "]   =    " + maxReports);
        maxReportsAll = (maxReportsAll > maxReports) ? maxReportsAll : maxReports;
      }
    }
    System.out.println(maxReportsAll);
  }

  private static int getMaxReports(int root, ArrayList<LinkedList<Integer> > adjacencyList) {
    ArrayDeque<Integer> reports = new ArrayDeque<Integer>();
    reports.add(root);
    int length = 0;
    while(reports.size()>0){
        int reportsSize = reports.size();
        for(int i = 0; i < reportsSize; i++) {
          int popped = reports.remove();
          for(int j = 0; j<adjacencyList.get(popped).size(); j++)
            reports.add(adjacencyList.get(popped).get(j));
      }
      length++;
    }
    return length;
  }
}
