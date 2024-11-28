#include <bits/stdc++.h>
using namespace std;


template<typename T>
class Fenwick {
    public:
    int n;
    vector<T> fen;
    Fenwick(int _n) {
        n = _n;
        fen = vector<T> (n + 1);
    }
    void add(int i, T x) {
        for (++i; i <= n; i += (i & -i)) fen[i] += x;
    }
    T query(int i) {
        T ans = 0;
        for (++i; i > 0; i -= (i & -i)) ans += fen[i];
        return ans;
    }
    T query(int l, int r) { return query(r) - query(l - 1); }
};


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    int LOG = 20;
    vector<vector<int>> g(n + 1), par(n + 1, vector<int> (LOG));
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> tin(n + 1), tout(n + 1), dist(n + 1);
    int t = 1;
    auto dfs = [&](auto self, int x, int y) -> void {
        tin[x] = t++;
        par[x][0] = y;
        for(int i = 1; i < LOG; i++) par[x][i] = par[par[x][i - 1]][i - 1];

        for(auto it : g[x]) if(it != y) {
            dist[it] = dist[x] + 1;
            self(self, it, x);
        }

        tout[x] = t;
    };

    dfs(dfs, 1, 0);

    auto LCA = [&](int x, int y) -> int {
        if(dist[x] < dist[y]) swap(x, y);
        int diff = dist[x] - dist[y];
        for(int i = 0; i < LOG; i++) if(diff >> i & 1) x = par[x][i];
        if(x == y) return x;
        for(int i = LOG - 1; i >= 0; i--) if(par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
        return par[x][0];
    };

    Fenwick<int> fen(n + 1);
    vector<int> ans(n + 1);

    for(int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        fen.add(tin[x], 1);
        if(x != y) fen.add(tin[y], 1);
        int l = LCA(x, y);
        fen.add(tin[par[l][0]], -2 + (x == y));
        if(x != y)
        ans[l] -= 1;
    }

    for(int i = 1; i <= n; i++) cout << ans[i] + fen.query(tin[i], tout[i] - 1) << ' ';
    cout << '\n';

}
