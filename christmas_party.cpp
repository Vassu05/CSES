#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> dp(n + 1);

    dp[0] = 1; // there were no cycles
    dp[1] = 0; // only one cycle but that is self
    int mod = 1e9 + 7;
    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i] + 1LL * dp[i - 1] * (i - 1) % mod) % mod; // sneak into one of the existing cycles by swapping gifts with one of the i - 1 members
        dp[i] = (dp[i] + 1LL * dp[i - 2] * (i - 1) % mod) % mod; // form a new cycle yourself with one of the i - 1 members
    }
    cout << dp[n] << '\n';
}
