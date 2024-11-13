#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;
int main(){
    const int N = 1e6;
    vector<int> dp(N + 1);
    int x = 1, y = 1;
    dp[1] = 2;
    for(int i = 2; i <= N; i++) {
        int nx = (1LL * x + y + x) % mod;
        int ny = (x + 1LL * 4 * y % mod) % mod;
        x = nx, y = ny;
        dp[i] = (x + y) % mod;
    } 
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}
