#include <bits/stdc++.h>
using namespace std;


class Lazy {
    public:
    long long val, lazy;
    Lazy() {
        val = lazy = 0;
    }
    Lazy(long long x) {
        val = x;
        lazy = 0;
    }
    Lazy(long long x, long long y) {
        val = x, lazy = y;
    }
};

template<typename T>
class Seg {
    #define _l 2 * i + 1
    #define _r 2 * i + 2
    public:
    int n;
    vector<T> seg;
    Seg(int _n) {
        n = _n;
        seg = vector<T> (4 * n, T());
    }
    T get(T x, T y) {
        return T(x.val + y.val);
    }
    void pull(int i, int l, int r) {
        if(l > r) return;
        seg[i].val += (r - l + 1) * seg[i].lazy;
        if(l < r) {
            seg[_l].lazy += seg[i].lazy;
            seg[_r].lazy += seg[i].lazy;
        }
        seg[i].lazy = 0;
    }
    void update(int i, int l, int r, int ll, int rr, T val) {
        pull(i, l, r);
        if(l > r || l > rr || r < ll) return;
        if(l >= ll && r <= rr) {
            seg[i].lazy += val.lazy;
            pull(i, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(_l, l, mid, ll, rr, val);
        update(_r, mid + 1, r, ll, rr, val);
        seg[i] = get(seg[_l], seg[_r]);
    }
    void update(int l, int r, T val) { update(0, 0, n - 1, l, r, val); }
    void update(int idx, T val) { update(idx, idx, val); }
    T query(int i, int l, int r, int ll, int rr) {
        pull(i, l, r);
        if(l > r || l > rr || r < ll) return T();
        if(l >= ll && r <= rr) return seg[i];
        int mid = (l + r) / 2;
        return get(query(_l, l, mid, ll, rr), query(_r, mid + 1, r, ll, rr));
    }
    T query(int l, int r) { return query(0, 0, n - 1, l, r); }
    T query(int idx) { return query(idx, idx); }
    #undef _l
    #undef _r
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

    Seg<Lazy> seg(n);

    for(int i = 0; i < n; i++) {
        seg.update(tin[i], tout[i] - 1, Lazy(0, a[i]));
    }

    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int s, x; cin >> s >> x;
            --s;
            seg.update(tin[s], tout[s] - 1, Lazy(0, x - a[s]));
            a[s] = x;
        }
        else {
            int x; cin >> x;
            --x;
            cout << seg.query(tin[x]).val << '\n';
        }
    }
}
