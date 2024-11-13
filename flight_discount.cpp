#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        --x, --y;
        g[x].emplace_back(y, z);
    }
    priority_queue<tuple<long long,long long,int>> q;
    vector<vector<long long>> dp(n, vector<long long> (2, 1e17));
    vector<int> vis(n);
    q.emplace(0, 0, 0);
    dp[0][0] = dp[0][1] = 0;
    while(!q.empty()) {
        auto [a, b, c] = q.top(); q.pop();
        a = -a, b = -b;
        if(dp[c][0] != a || dp[c][1] != b) continue;
        for(auto [v, w] : g[c]) {
            bool put = false;
            if(dp[v][0] > dp[c][0] + w) {
                dp[v][0] = dp[c][0] + w;
                put = true;
            }
            if(dp[v][1] > dp[c][1] + w) {
                dp[v][1] = dp[c][1] + w;
                put = true;
            }
            if(dp[v][1] > dp[c][0] + w / 2) {
                dp[v][1] = dp[c][0] + w / 2;
                put = true;
            }
            if(put) q.emplace(-dp[v][0], -dp[v][1], v);
        }
    }
    cout << dp[n - 1][1] << '\n';
}
