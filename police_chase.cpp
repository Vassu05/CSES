#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n), g(n, vector<int> (n));

    vector<pair<int,int>> edges;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        edges.emplace_back(x, y);
        adj[x].push_back(y);
        adj[y].push_back(x);
        g[x][y] += 1;
        g[y][x] += 1;
    }

    vector<int> par(n, -1);

    auto reachable = [&]() -> bool {
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int x = q.front(); q.pop();
            for(auto j : adj[x]) {
                if(j && par[j] == -1 && g[x][j] > 0) {
                    par[j] = x;
                    q.push(j);
                }
            }
        }
        return par[n - 1] != -1;
    };

    int ans = 0;

    while(reachable()) {
        int last = n - 1;
        int find = m + 1;

        while(par[last] != -1) {
            find = min(find, g[par[last]][last]);
            last = par[last];
        }

        ans += find;

        last = n - 1;

        while(par[last] != -1) {
            g[par[last]][last] -= find;
            g[last][par[last]] += find;
            last = par[last];
        }

        par = vector<int> (n, -1);
    }

    vector<int> vis(n, 0);

    auto dfs = [&](auto self, int x) -> void {
        vis[x] = 1;
        for(auto it : adj[x]) if(g[x][it] > 0 && !vis[it]) {
            self(self, it);
        }
    };

    dfs(dfs, 0);

    cout << ans << '\n';

    for(auto [x, y] : edges) if((vis[x] && !vis[y]) || (!vis[x] && vis[y])){
        cout << x + 1 << ' ' << y + 1 << '\n';
    }
}
