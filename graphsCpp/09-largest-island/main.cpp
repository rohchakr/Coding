#include <bits/stdc++.h>
using namespace std;

bool isInsideRange(int num, int lowerBound, int upperBound) {
    return num >= lowerBound && num < upperBound;
}

int traverseDfs(vector<vector<int>>& grid, int rowIndex, int colIndex, int m, int n) {
    // Neighbors = [0, -1], [0, 1], [-1, 0], [1, 0]
    // Neighbors = left, right, up, down
    int neighborX[] = {0, 0, -1, 1};
    int neighborY[] = {-1, 1, 0, 0};
    int area = 1;
    for (int i = 0; i < 4; i++) {
        int candidateX = rowIndex + neighborX[i];
        int candidateY = colIndex + neighborY[i];
        if (isInsideRange(candidateX, 0, m) && isInsideRange(candidateY, 0, n) && grid[candidateX][candidateY] == 1) {
            grid[candidateX][candidateY] = 0;
            area += traverseDfs(grid, candidateX, candidateY, m, n);
        }
    }
    return area;
}

int maxAreaOfIsland(vector<vector<int>> grid)
{
    int maxArea = 0;
    int m = grid.size();
    int n = grid[0].size();
    // If visited, mark grid[i][j] as 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                int areaOfIsland = traverseDfs(grid, i, j, m, n);
                maxArea = (maxArea > areaOfIsland) ? maxArea : areaOfIsland;
            }
        }
    }
    return maxArea;
}

void solve() {
    int m, n;
    cin>>m>>n;
    vector< vector<int> > grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>grid[i][j];
        }
    }
    cout<<maxAreaOfIsland(grid)<<"\n";
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