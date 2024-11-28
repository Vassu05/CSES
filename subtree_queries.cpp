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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> tin(n), tout(n);
    int t = 0;
    auto dfs = [&](auto self, int x, int y) -> void {
        tin[x] = t++;
        for(auto it : g[x]) if(it != y) self(self, it, x);
        tout[x] = t;
    };
    dfs(dfs, 0, 0);

    Fenwick<long long> fen(n);

    for(int i = 0; i < n; i++) fen.add(tin[i], a[i]);

    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int s, x; cin >> s >> x;
            --s;
            fen.add(tin[s], x - a[s]);
            a[s] = x;
        }
        else {
            int x; cin >> x;
            --x;
            cout << fen.query(tin[x], tout[x] - 1) << '\n';
        }
    }

}
