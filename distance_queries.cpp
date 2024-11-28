#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> d(n, 0);
    int LOG = 20;
    vector<vector<int>> par(n, vector<int> (LOG));

    auto dfs = [&](auto self, int x, int y) -> void {
        par[x][0] = y;
        for(int i = 1; i < LOG; i++) par[x][i] = par[par[x][i - 1]][i - 1];
        for(auto it : g[x]) if(it != y) {
            d[it] = d[x] + 1;
            self(self, it, x);
        }
    };

    dfs(dfs, 0, 0);

    auto LCA = [&](int x, int y) -> int {
        if(d[x] < d[y]) swap(x, y);
        int diff = d[x] - d[y];
        for(int i = 0; i < LOG; i++) if(diff >> i & 1) x = par[x][i];
        if(x == y) return x;
        for(int i = LOG - 1; i >= 0; i--) if(par[x][i] != par[y][i]) x = par[x][i], y = par[y][i];
        return par[x][0];
    };

    while(q--) {
        int x, y; cin >> x >> y;
        --x, --y;
        cout << d[x] + d[y] - 2 * d[LCA(x, y)] << '\n';
    }
}
