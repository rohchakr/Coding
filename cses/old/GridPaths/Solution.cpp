#include<iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    char grid[n + 1][n + 1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin>>grid[i + 1][j + 1];
    
    int numPaths[n + 1][n + 1];
    char TRAP = '*';
    int MOD = 1000000007;

    // base case
    numPaths[n][n] = (grid[n][n] == TRAP) ? 0 : 1;

    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            // base case
            if (i == n && j == n) {
                continue;
            }

            numPaths[i][j] = 0;
        
            if (grid[i][j] != TRAP) {
                if (i + 1 <= n)
                    numPaths[i][j] += numPaths[i + 1][j];
                if (j + 1 <= n)
                    numPaths[i][j] += numPaths[i][j + 1];
                numPaths[i][j] %= MOD;
            }
        }
    }

    cout<<numPaths[1][1]<<"\n";

    return 0;
}