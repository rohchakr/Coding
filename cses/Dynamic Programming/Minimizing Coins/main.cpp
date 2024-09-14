#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
#include<unordered_map>
#include<deque>
#include<cmath>
#include<climits>

using namespace std;

class Solution {
public:
    void solve()
    {
        int n,x;
        cin>>n>>x;
        int c[n];
        for (int i = 0; i < n; i++)
            cin>>c[i];
        int sum[x + 1];
        for (int i = 1; i <= x; i++) {
            sum[i] = INT_MAX;
            for (int j = 0; j < n; j++) {
                // latest coin at hand is c[j]
                if (i == c[j]) {
                    // sum is 1 if c[j] is equal to i
                    sum[i] = 1;
                    break;
                } else if ((i - c[j] > 0) && sum[i - c[j]] != INT_MAX && sum[i] > (sum[i - c[j]] + 1)) {
                    // if we pick up c[j], then sum is minSum[x - c[j]] + 1
                    sum[i] = sum[i - c[j]] + 1;
                }
            }
        }
        int numCoins = (sum[x] == INT_MAX) ? -1 : sum[x];
        cout<<numCoins<<"\n";
    }
};

int main() {
    #ifdef LOCAL_RUN
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int tc = 1;
    // scanf("%d ", &tc);
    while (tc--) {
        // Take inputs
        Solution ob;
        ob.solve();
    }
    return 0;
}
