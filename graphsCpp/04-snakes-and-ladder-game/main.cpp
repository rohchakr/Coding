#include <bits/stdc++.h>
using namespace std;

int min_dice_throws(int n, vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    vector< vector<int> > adjList(n + 1);
    unordered_map<int, int> snakeLadderMap;
    
    for (pair<int, int> snake : snakes)
        snakeLadderMap[snake.first] = snake.second;
    for (pair<int, int> ladder : ladders)
        snakeLadderMap[ladder.first] = ladder.second;

    // Fill dice moves
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            int currentIndex = i + j;
            if (currentIndex <= n) {
                int value = (snakeLadderMap.find(currentIndex) == snakeLadderMap.end()) ? currentIndex : snakeLadderMap[currentIndex];
                adjList[i].push_back(value);
            }
        }
    }

    // BFS for shortest path
    vector<bool> visited(n + 1);
    vector<int> distance(n + 1, -1);
    queue<int> traversalQueue;
    visited[1] = true;
    traversalQueue.push(1);
    distance[1] = 0;

    while(!traversalQueue.empty()) {
        int front = traversalQueue.front();
        traversalQueue.pop();
        for (int neighbor : adjList[front]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[front] + 1;
                traversalQueue.push(neighbor);
            }
        }
    }

    return distance[n];
}

void solve() {
    int n, ladders, snakes, a, b;
    cin >> n;
    cin>>ladders;
    vector<pair<int, int> > ladderList(ladders);
    for (int i = 0; i < ladders; i++) {
        cin>>a>>b;
        ladderList[i] = {a, b};
    }
    cin>>snakes;
    vector<pair<int, int> > snakeList(snakes);
    for (int i = 0; i < snakes; i++) {
        cin>>a>>b;
        snakeList[i] = {a, b};
    }
    cout<<min_dice_throws(n, snakeList, ladderList)<<"\n";
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