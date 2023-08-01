#include <bits/stdc++.h>
using namespace std;

void performDfs(vector<vector<int> > adjacencyList, int vertex, vector<bool> &visited, int &connectedVerticesCount) {
    for (int neighbor : adjacencyList.at(vertex)) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            connectedVerticesCount++;
            performDfs(adjacencyList, neighbor, visited, connectedVerticesCount);
        }
    }
}

int count_pairs(int N, vector<pair<int,int> > astronauts){
    // Find connected components and number of vertices in each
    vector<int> connectedCompomentVerticesCount; // We can get rid of extra space
    vector< vector<int> > adjacencyList(N, vector<int>());
    // Fill adjList
    for (pair<int, int> astronaut : astronauts) {
        adjacencyList.at(astronaut.first).push_back(astronaut.second);
        adjacencyList.at(astronaut.second).push_back(astronaut.first);
    }
    vector<bool> visited(N, false);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            int connectedVerticesCount = 1;
            performDfs(adjacencyList, i, visited, connectedVerticesCount);
            connectedCompomentVerticesCount.push_back(connectedVerticesCount);
        }
    }

    // Result = nC2 - forEachConnectedComponentC2
    int validPairs = (N * (N - 1)) / 2;
    for (int value : connectedCompomentVerticesCount) {
        validPairs -= (value * (value - 1)) / 2;
    }

    return validPairs;
}

void solve() {
    int vertices;
    cin >> vertices;
    int edges;
    cin >> edges;
    vector<pair<int,int> > edgeList(edges);
    for (int i = 0; i < edges; i++) {
        pair<int, int> input;
        cin>>input.first>>input.second;
        edgeList[i] = input;
    }
    cout<<count_pairs(vertices, edgeList)<<"\n";
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