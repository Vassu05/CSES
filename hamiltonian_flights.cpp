#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n, vector<int> (n));
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[--x][--y] += 1;
    }
    vector<vector<int>> dp((1 << n), vector<int> (n));
    int mod = 1e9 + 7;
    auto add = [&](int x, int y) -> int {
        int ans = x + y;
        if(ans >= mod) ans -= mod;
        return ans;
    };
    dp[1][0] = 1;
    for(int i = 0; i < 1 << n; i++) {
        for(int j = 0; j < n; j++) if(dp[i][j] > 0) {
            for(int k = 0; k < n; k++) if(g[j][k] && (i >> k & 1 ^ 1)) {
                int ni = (i ^ (1 << k));
                dp[ni][k] = add(dp[ni][k], 1LL * g[j][k] * dp[i][j] % mod);
            }
        }
    }
    cout << dp.back()[n - 1] << '\n';
}
