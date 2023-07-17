#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void traverseDFS(vector<vector<int> >& rooms, int currentNode, vector<bool>& visited) {
        if (visited[currentNode])
            return;

        visited[currentNode] = true;
        for (int neighbor : rooms[currentNode]) {
            traverseDFS(rooms, neighbor, visited);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int v = rooms.size();
        vector<bool> visited(v);
        traverseDFS(rooms, 0, visited);
        for (bool i : visited)
            if (!i)
                return false;
        return true;
    }
};

void solve() {
    int v, numNeighbors, neighbor;
    cin>>v;
    vector< vector<int> > rooms(v);
    for (int i = 0; i < v; i++) {
        cin>>numNeighbors;
        for (int j = 0; j < numNeighbors; j++) {
            cin>>neighbor;
            rooms[i].push_back(neighbor);
        }
    }
    Solution s;
    cout<<s.canVisitAllRooms(rooms)<<"\n";
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