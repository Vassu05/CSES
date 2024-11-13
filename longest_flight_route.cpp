#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> in(n), vis(n);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
    }
    auto dfs = [&](auto self, int x) -> void {
        vis[x] = 1;
        for(auto it : g[x]) { 
            in[it] += 1;
            if(!vis[it]) self(self, it);
        }
    };
    dfs(dfs,0);
    vector<int> dp(n, 0), par(n, -1);
    dp[0] = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int y = q.front(); q.pop();
        for(auto it : g[y]) {
            if(dp[it] < dp[y] + 1) {
                dp[it] = dp[y] + 1;
                par[it] = y;
            }
            if(--in[it] == 0) q.push(it);
        }
    }
    if(dp[n - 1] == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << dp[n - 1] << '\n';
    int now = n - 1;
    vector<int> ans;
    while(now != -1) {
        ans.push_back(now + 1);
        now = par[now];
    }
    reverse(ans.begin(), ans.end());
    for(int i : ans) cout << i << ' ';
    cout << '\n';
}
