#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int mod = 1e9 + 7;
    vector<int> dp(n + 1);
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = i - 1; j >= max(1, i - 6); j--) {
            dp[i] = (dp[i] + dp[j]) % mod;
        }
        dp[i] = (dp[i] + (i <= 6)) % mod;
    }
    cout << dp[n] << '\n';
}
