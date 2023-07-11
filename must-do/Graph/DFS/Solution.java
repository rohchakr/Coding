//{ Driver Code Starts
// Initial Template for Java
import java.util.*;
import java.lang.*;
import java.io.*;

class Solution {
    // Function to return a list containing the DFS traversal of the graph.
    public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        ArrayList<Integer> ans = new ArrayList<>();
        boolean visited[] = new boolean[V]; // initialized with false;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                getNodesInDFSOrder(i, adj, visited, ans);
            }
        }
        return ans;
    }

    private void getNodesInDFSOrder(int currentNode, ArrayList<ArrayList<Integer>> adj, boolean[] visited, ArrayList<Integer> ans) {
        if (visited[currentNode])
            return;

        visited[currentNode] = true;
        ans.add(currentNode);

        for (Integer i : adj.get(currentNode)) {
            getNodesInDFSOrder(i, adj, visited, ans);
        }
    }
}