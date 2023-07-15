#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int> verticesScanned;
        vector<vector <int> >::iterator edgePointer = edges.begin();
        // Scan the first edge
        verticesScanned.insert((*edgePointer)[0]);
        verticesScanned.insert((*edgePointer)[1]);
        edgePointer++;
        for (;edgePointer!=edges.end();edgePointer++) {
            vector<int> edge = *edgePointer;
            if (verticesScanned.find(edge[0]) != verticesScanned.end() && verticesScanned.find(edge[1]) != verticesScanned.end()) {
                // duplicate edge
                continue;
            }
            // Non-duplicate edge
            // Return the vertex which is already scanned
            if (verticesScanned.find(edge[0]) != verticesScanned.end())
                return edge[0];
            return edge[1];
        }
        return -1;
    }
};

void solve() {
    int edges, a, b;
    cin>>edges;
    vector<vector<int> > edgeList;
    for (int i = 0;i < edges;i++) {
        cin>>a>>b;
        vector<int> edge;
        edge.push_back(a);
        edge.push_back(b);
        edgeList.push_back(edge);
    }
    Solution s;
    cout<<s.findCenter(edgeList)<<"\n";
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