#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
#include<unordered_map>
#include<deque>
#include<cmath>

using namespace std;

class Solution {
public:
    void solve()
    {
        cout<<"Hello";
    }
};

int main() {
    #ifdef LOCAL_RUN
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        // Take inputs
        Solution ob;
        ob.solve();
    }
    return 0;
}
