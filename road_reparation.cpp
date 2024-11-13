#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        --x, --y;
        g[x].emplace_back(y, z);
        g[y].emplace_back(x, z);
    }
    priority_queue<pair<int,int>> q;
    q.emplace(0, 0);
    vector<int> vis(n);
    int count = 0, ans = 0;
    while(!q.empty()) {
        auto [d, x] = q.top(); q.pop();
        d = -d;
        if(vis[x]) continue;
        ans += d;
        count += 1;
        vis[x] = 1;
        for(auto [it, w] : g[x]) if(!vis[it]) {
            q.emplace(-w, it);
        }
    }

    cout << (count == n ? to_string(ans) : "IMPOSSIBLE\n");
}
