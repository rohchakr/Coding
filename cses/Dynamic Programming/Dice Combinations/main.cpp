#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
#include<unordered_map>
#include<deque>
#include<cmath>

#define MOD 1000000007

using namespace std;

class Solution {
public:
    void solve(int n)
    {
        // int size = (n > 7) ? n : 7;
        // int a[size]; // Can be further optimized by using a circular queue
        // Time complexity : O(n)
        // Space complexity : O(1)
        int a[7];
        a[0] = 1;
        int sumOfPrev6 = 0;
        int i = 0;
        for (i = 1; i < 6; i++) {
            sumOfPrev6 += a[i - 1];
            a[i] = sumOfPrev6 + 1;
        }

        // i = 6
        sumOfPrev6 += a[i - 1];
        a[6] = sumOfPrev6; // no plus 1 here

        int aIndex = 0;
        for (i = 7; i < n; i++) {
            // sumOfPrev6 = (sumOfPrev6 - a[i - 7] + a[i - 1]) % MOD;
            aIndex = (i - 7) % 7;
            sumOfPrev6 = sumOfPrev6 - a[aIndex];
            if (sumOfPrev6 < 0)
                sumOfPrev6 += MOD;
            aIndex = (i - 1) % 7;
            sumOfPrev6 = (sumOfPrev6 + a[aIndex]) % MOD;
            aIndex = i % 7;
            a[aIndex] = sumOfPrev6;
        }
        aIndex = (n - 1) % 7;
        cout<<a[aIndex]<<"\n";
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
        int n;
        cin>>n;
        Solution ob;
        ob.solve(n);
    }
    return 0;
}

