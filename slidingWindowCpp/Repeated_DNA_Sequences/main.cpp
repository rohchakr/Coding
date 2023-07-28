#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> dnaMap;
        vector<string> result;
        if (s.size() < 11)
            return result;
            
        int winLen = 10;
        for (int i = 0; i < s.size() - 9; i++) {
            string cur = s.substr(i, 10);
            if (dnaMap.find(cur) == dnaMap.end())
                dnaMap.insert({cur, 1});
            else
                dnaMap.at(cur)++;
        }

        for (pair<string, int> i : dnaMap) {
            if (i.second > 1)
                result.push_back(i.first);
        }

        return result;
    }
};

void solve() {
    string input;
    cin>>input;
    Solution s;
    vector<string> result = s.findRepeatedDnaSequences(input);
    for (string str : result)
        cout<<str<<" ";
    cout<<"\n";
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