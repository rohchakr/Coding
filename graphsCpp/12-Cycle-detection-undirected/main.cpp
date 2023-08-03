#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int> > edges, vector<bool> &visited, int vertex, int referrer) {
    for (int neighbor : edges[vertex]) {
        if (visited[neighbor] && referrer != neighbor)
            return true;

        else if (!visited[neighbor]) {
            visited[neighbor] = true;
            bool recursiveResult = isCycle(edges, visited, neighbor, vertex);
            if (recursiveResult)
                return true;
        }
    }

    return false;
}

bool solve(int n, vector<vector<int> > edges) {
    vector<vector<int> > adjList(n + 1, vector<int>());
    for (vector<int> edge : edges) {
        int u = edge[0], v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            if (isCycle(adjList, visited, i, i))
                return true;
        }
    }

    return false;
}

void solve() {
    int n, edges;
    cin>>n>>edges;
    vector<vector<int> > edgeList(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int u,v;
        cin>>u>>v;
        edgeList[i] = {u, v};
    }
    cout<<solve(n, edgeList)<<"\n";
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