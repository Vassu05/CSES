#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n), f(n);
    vector<vector<int>> g(n, vector<int> (n));

    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x][y] += 1;
        adj[x].emplace_back(y, i);
        f[x].emplace_back(y, i);
        adj[y].emplace_back(x, i);
    }

    vector<int> par(n, -1);

    auto reachable = [&]() -> bool {
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int x = q.front(); q.pop();
            for(auto [j, idx] : adj[x]) if(j && par[j] == -1 && g[x][j] > 0) {
                par[j] = x;
                q.push(j);
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
            g[par[last]][last] -= 1;
            g[last][par[last]] += 1;
            last = par[last];
        }
        par = vector<int> (n, -1);
    }

    cout << ans << '\n';

    vector<int> path, vis(m, 0);

    auto dfs = [&](auto self, int x) -> void {
        path.push_back(x);
        if(x == n - 1) return;
        for(auto [it, idx] : f[x]) if(!vis[idx] && g[x][it] == 0) {
            vis[idx] = 1;
            self(self, it);
            return;
        }
    };

    for(int i = 0; i < ans; i++) {
        path.clear();
        dfs(dfs, 0);
        cout << path.size() << '\n';
        for(int &i : path) cout << i + 1 << ' ';
        cout << '\n';
    }

}
