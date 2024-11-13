#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    int dp[m + 1], ndp[m + 1], mod = 1e9 + 7;
    for(int i = 1; i <= m; i++) dp[i] = 1, ndp[i] = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        for(int j = 1; j <= m; j++) {
            if(x && x != j) continue;
            int now = dp[j];
            if(j > 1) now = (now + dp[j - 1]) % mod;
            if(j < m) now = (now + dp[j + 1]) % mod;
            ndp[j] = now;
            if(i == 0) ndp[j] = 1;
        }
        for(int j = 1; j <= m; j++) {
            dp[j] = ndp[j];
            ndp[j] = 0;
        }
    }
    int ans = 0;
    for(int j = 1; j <= m; j++) ans = (ans + dp[j]) % mod;
    cout << ans << '\n';
}
