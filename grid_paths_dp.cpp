#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<string> a(n); 
    for(auto &s : a) cin >> s;
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int> (n));
    if(a[0][0] != '*') dp[0][0] = 1;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        if(i == 0 && j == 0) continue;
        if(a[i][j] == '*') continue;
        int now = 0;
        if(i) now = (now + dp[i - 1][j]) % mod;
        if(j) now = (now + dp[i][j - 1]) % mod;
        dp[i][j] = now;
    }
    cout << dp[n - 1][n - 1] << '\n';
}
