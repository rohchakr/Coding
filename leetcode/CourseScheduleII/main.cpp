#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> currentIndegree(numCourses);
    vector<vector<int>> adjList(numCourses, vector<int>());
    queue<int> traversalQueue;
    vector<int> order;

    for (vector<int> edge : prerequisites)
    {
        currentIndegree[edge[0]]++;
        adjList[edge[1]].push_back(edge[0]); // lexical ordering needs to be handled here
    }

    for (int i = 0; i < numCourses; i++)
    {
        if (currentIndegree[i] == 0)
            traversalQueue.push(i);
    }

    // BFS
    while (!traversalQueue.empty())
    {
        int currentVertex = traversalQueue.front();
        traversalQueue.pop();
        order.push_back(currentVertex);
        {
            for (int neighbor : adjList[currentVertex]) {
                currentIndegree[neighbor]--;
                if (currentIndegree[neighbor] == 0)
                    traversalQueue.push(neighbor);
                // if already pushed, indegree will be negative
                // no element will be pushed more than once
            }
        }
    }

    vector<int> newVec;
    return (order.size() == numCourses) ? order : newVec;
}

void solve()
{
    int vertices, edges;
    cin >> vertices >> edges;
    vector<vector<int>> edgeList(edges, vector<int>());
    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;
        edgeList[i] = {a, b};
    }
    vector<int> order = findOrder(vertices, edgeList);
    cout << order.size() << "\n";
    for (int i = 0; i < order.size(); i++)
    {
        cout << order[i] << " ";
    }
    cout << "\n";
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