#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n + m + 2, vector<int> (n + m + 2)), adj(n + m + 2);

    for(int i = 1; i <= n; i++) {
        g[0][i] = 1;
        adj[0].push_back(i);
        adj[i].push_back(0);
    }

    vector<pair<int,int>> edges;

    for(int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        g[x][n + y] = 1;
        edges.emplace_back(x, y);
        adj[x].push_back(n + y);
        adj[n + y].push_back(x);
    }

    for(int i = n + 1; i <= n + m; i++) {
        g[i][n + m + 1] = 1;
        adj[i].push_back(n + m + 1);
        adj[n + m + 1].push_back(i);
    }

    auto begin = g;

    vector<int> par(n + m + 2, -1);

    auto reachable = [&]() -> bool {
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int x = q.front(); q.pop();
            for(auto j : adj[x]) if(j && par[j] == -1 && g[x][j] > 0) {
                par[j] = x;
                q.push(j);
            }
        }
        return par[n + m + 1] != -1;
    };

    int ans = 0;

    while(reachable()) {
        int last = n + m + 1;
        int find = n + m + 1;

        while(par[last] != -1) {
            find = min(find, g[par[last]][last]);
            last = par[last];
        }

        ans += find;

        last = n + m + 1;

        while(par[last] != -1) {
            g[par[last]][last] -= 1;
            g[last][par[last]] += 1;
            last = par[last];
        }

        par = vector<int> (n + m + 2, -1);
    }

    cout << ans << '\n';

    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
        if(begin[i][j + n] && !g[i][j + n]) cout << i << ' ' << j << '\n';
    }
}
