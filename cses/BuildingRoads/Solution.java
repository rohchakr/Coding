import java.util.*;

public class Solution {
    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int m = s.nextInt();
        boolean[] visited = new boolean[n + 1];
        LinkedList<Integer>[] adjList = new LinkedList[n + 1];
        for (int i = 0; i < n + 1; i++)
            adjList[i] = new LinkedList<Integer>();

        for (int i = 0; i < m; i++) {
            int a = s.nextInt();
            int b = s.nextInt();
            adjList[a].push(b);
            adjList[b].push(a);
        }
        LinkedList<Integer> stack = new LinkedList<>();

        int connComp = 0;
        LinkedList<Integer> roadStart = new LinkedList<>();
        LinkedList<Integer> roadEnd = new LinkedList<>();

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                stack.push(i);
                if (connComp != 0) {
                    roadEnd.push(i);
                }
                connComp++;
            }
            
            int city = 0;
            while(!stack.isEmpty()) {
                city = stack.pop();
                visited[city] = true;
                for (int adjCity : adjList[city]) {
                    if (!visited[adjCity])
                        stack.push(adjCity);
                }
            }
            if (city != 0)
                roadStart.push(city);
        }

        System.out.println(connComp - 1);
        for (int i = 0; i < connComp - 1; i++) {
            System.out.println(roadStart.removeLast() + " " + roadEnd.removeLast());
        }
    }
}