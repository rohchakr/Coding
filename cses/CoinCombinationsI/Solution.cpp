#include<iostream>
using namespace std;

int main() {
    int n, x;
    cin>>n;
    cin>>x;
    int c[n];
    for (int i = 0; i < n; i++)
        cin>>c[i];
    int dp[x + 1];
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        dp[i] = 0;
        for (int j = 0; j < n; j++) {
            int c_at_j = c[j];
            if (i - c_at_j >= 0)
                dp[i] = (dp[i] + dp[i - c_at_j]) % 1000000007;
        }
    }
    cout<<dp[x]<<"\n";
    return 0;
}