#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int main() {
    int MAX = 1000000; // can find a more suitable one
    int n;
    cin>>n;
    int dp[n + 1]; // don't need this much space
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        stack<int> digits;
        int num = i;
        while (num != 0) {
            digits.push(num % 10);
            num /= 10;
        }
        dp[i] = MAX;
        while(!digits.empty()) {
            int digit = digits.top();
            digits.pop();
            dp[i] = min(dp[i], dp[i - digit] + 1);
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}