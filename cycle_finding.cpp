#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> edges(m, vector<int> (3));
    for(int i = 0; i < m; i++) for(int j = 0; j < 3; j++) cin >> edges[i][j];
    for(int i = 0; i < m; i++) --edges[i][0], --edges[i][1];
    vector<int> dp(n, 1e18), par(n, -1);
    auto perform = [&]() {
        for(auto it : edges) {
            int x = it[0], y = it[1], z = it[2];
            if(dp[y] > dp[x] + z) {
                dp[y] = dp[x] + z;
                par[y] = x;
            }
        }
    };
    dp[0] = 0;
    for(int i = 0; i < n; i++) perform();
    vector<int> ndp = dp;
    perform();
    int found = -1;
    for(int i = 0; i < n; i++) if(dp[i] != ndp[i]) found = i;
    if(found == -1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    dp = vector<int> (n, 1e18);
    dp[found] = 0;
    for(int i = 0; i < n; i++) perform();
    vector<int> vis(n), ans;
    int now = found;
    while(!vis[now]) {
        assert(now != -1);
        ans.push_back(now);
        vis[now] = 1;
        now = par[now];
    }
    ans.push_back(now);
    reverse(ans.begin(), ans.end());
    while(ans.back() != ans[0]) ans.pop_back();
    for(int i : ans) cout << i + 1 << ' ';
    cout << '\n';
}
