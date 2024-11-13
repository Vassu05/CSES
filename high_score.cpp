#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, m; cin >> n >> m;
    vector<tuple<int,int,int>> g;
    vector<vector<int>> G(n);
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        --x, --y;
        g.emplace_back(x, y, z);
        G[y].push_back(x);
    }
    vector<int> dp(n, -1e18);
    dp[0] = 0;
    auto perform = [&](){
        for(auto [x, y, z] : g) {
            dp[y] = max(dp[y], dp[x] + z);
        }
    };
    for(int i = 0; i < n; i++) perform();
    vector<int> ndp = dp;
    perform();
    vector<int> vis(n);
    auto dfs = [&](auto self, int x) -> void {
        vis[x] = 1;
        for(auto it : G[x]) if(!vis[it]) self(self, it);
    };
    dfs(dfs, n - 1);
    for(int i = 0; i < n; i++) {
        if(dp[i] != ndp[i] && vis[i] && dp[i] > -1e16) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << dp[n - 1] << '\n';
}
