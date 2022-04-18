#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<iterator>
using namespace std;

int main() {
    int n, m, a, b;
    cin>>n>>m;
    bool visited[n + 1];
    for (int i = 0; i <= n; i++) {
        visited[i] = false;
    }
    vector<int> adjList[n + 1];

    for (int i = 0; i < m; i++) {
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    stack<int> cityStack;

    int connComp = 0;
    queue<int> roadStart, roadEnd;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cityStack.push(i);
            if (connComp != 0) {
                roadEnd.push(i);
            }
            connComp++;
        }

        int city = 0;
        while (!cityStack.empty()) {
            city = cityStack.top();
            cityStack.pop();
            visited[city] = true;
            // for (int adjCity : adjList[city]) {
            vector<int>::iterator it;
            for (it = adjList[city].begin(); it != adjList[city].end(); it++) {
               if (!visited[*it])
                cityStack.push(*it); 
            }
        }
        if (city != 0)
            roadStart.push(city);
    }

    cout<<connComp - 1<<"\n";
    for (int i = 0; i < connComp - 1; i++) {
        cout<<roadStart.front()<<" "<<roadEnd.front()<<"\n";
        roadStart.pop();
        roadEnd.pop();
    }

    return 0;
}