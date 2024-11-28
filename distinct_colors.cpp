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
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int t = 0;
    map<int, vector<int>> mp;
    vector<int> next(n, -1), ans(n), tin(n), tout(n);
    Fenwick<int> fen(n);

    auto dfs = [&](auto self, int x, int y) -> void {
        tin[x] = t++;
        if(mp[a[x]].size() == 0) fen.add(tin[x], 1);
        else next[mp[a[x]].back()] = x;
        mp[a[x]].push_back(x);
        for(auto it : g[x]) if(it != y) self(self, it, x);
        tout[x] = t;
    };

    dfs(dfs, 0, 0);

    auto get = [&](auto self, int x, int y) -> void {
        ans[x] = fen.query(tin[x], tout[x] - 1);
        if(next[x] != -1) fen.add(tin[next[x]], 1);
        for(auto it : g[x]) if(it != y) self(self, it, x);
    };
    get(get, 0, 0);

    for(int i : ans) cout << i << ' ';
    cout << '\n';
}
