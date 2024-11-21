#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n, vector<int> (n));
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        --x, --y;
        g[x][y] += w;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> par(n, -1);

    auto reachable = [&]() -> bool {
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            auto x = q.front(); q.pop();
            for(int j : adj[x]) {
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
        int find = 1e16;

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

    cout << ans << '\n';
}
