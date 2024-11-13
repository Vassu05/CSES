#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        g[--x].emplace_back(--y, z);
    }
    vector<int> dist(n, 1e17);
    dist[0] = 0;
    priority_queue<pair<int,int>> q;
    q.emplace(0, 0);
    while(!q.empty()) {
        auto [d, x] = q.top(); q.pop();
        d = -d;
        if(dist[x] != d) continue;
        for(auto [it, w] : g[x]) if(dist[it] > d + w) {
            dist[it] = d + w;
            q.emplace(-dist[it], it);
        }
    }
    for(int i : dist) cout << i << ' ';
    cout << '\n';
}
