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

int main() {
    int n, q; cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    Fenwick<long long> fen(n);
    for(int i = 0; i < n; i++) {
        fen.add(i, a[i]);
    }
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int idx, val; cin >> idx >> val;
            idx -= 1;
            fen.add(idx, val - a[idx]);
            a[idx] = val;
        }
        else {
            int l, r; cin >> l >> r;
            --l, --r;
            cout << fen.query(l, r) << '\n';
        }
    }
}