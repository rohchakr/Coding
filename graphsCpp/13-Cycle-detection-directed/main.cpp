#include <bits/stdc++.h>
using namespace std;

bool visit(vector<vector<int> > edges, int currentVertex, vector<bool> &visited, unordered_set<int> currentPathVertices) {
    for (int vertex : edges[currentVertex]) {
        if (visited[vertex]) {
            if (currentPathVertices.find(vertex) != currentPathVertices.end()) {
                // cycle found
                return true;
            }
        } else {
            visited[vertex] = true;
            currentPathVertices.insert(vertex);
            if (visit(edges, vertex, visited, currentPathVertices))
                return true;
        }
    }
    return false;
}

bool solve(int n, vector<vector<int>>edges) {
    vector<vector<int> > adjList(n + 1, vector<int>());
    for (vector<int> edge : edges) {
        adjList[edge[0]].push_back(edge[1]);
    }
    
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <=n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            if (visit(adjList, i, visited, {i}))
                return true;
        }
    }
    
    return false;
}

void solve() {
    int vertices, edges;
    cin>>vertices>>edges;
    vector<vector<int> > edgeList(edges);
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin>>u>>v;
        edgeList[i] = {u, v};
    }
    cout<<solve(vertices, edgeList)<<"\n";
}

int main() {
    #ifdef LOCAL_RUN
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}