#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> graph, int currentVertex, vector<bool> &visited, int parentVertex, int currentCoveredVerticesLength)
{
    for (int neighbor : graph[currentVertex])
    {
        if (visited[neighbor])
        {
            if (neighbor == parentVertex)
            {
                // no cycle, ignore because parent is already covered earlier
                // continue;
            } else if (currentVertex == parentVertex) {
                // 1st vertex
                // it's a cycle
                // if its neighbor is visited, then all cases are already covered, no need to process again
                // continue;
            }
            else
            {
                // it is a cycle
                if (((currentCoveredVerticesLength) % 2 == 1))
                {
                    // odd length cycle
                    // cout<<currentCoveredVerticesLength<<", Neighbor: "<<neighbor<<", Current vertex: "<<currentVertex<<", Parent vertex: "<<parentVertex<<"\n";
                    return false;
                } 
            }
        }
        else
        {
            visited[neighbor] = true;
            if (!isBipartite(graph, neighbor, visited, currentVertex, currentCoveredVerticesLength + 1))
                return false;
            // else
            //     continue;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> graph)
{
    int vertices = graph.size();
    vector<bool> visited(vertices); // All initialized to false;
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            if (!isBipartite(graph, i, visited, i, 1))
                return false;
        }
    }
    return true;
}

void solve()
{
    int vertices;
    cin >> vertices;
    vector<vector<int>> adjList(vertices, vector<int>());
    for (int i = 0; i < vertices; i++)
    {
        int neighbors;
        cin >> neighbors;
        for (int j = 0; j < neighbors; j++)
        {
            int num;
            cin >> num;
            adjList[i].push_back(num);
        }
    }
    cout << isBipartite(adjList) << "\n";
}

int main()
{
#ifdef LOCAL_RUN
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}