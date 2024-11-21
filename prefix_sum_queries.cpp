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
        seg = vector<T> (4 * n);
    }
    T get(T x, T y) {
        return T(max(x.val, y.val), 0);
    }
    void pull(int i, int l, int r) {
        if(l > r) return;
        seg[i].val += seg[i].lazy;
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
        if(l > r || l > rr || r < ll) return -1e18;
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
    Seg<Lazy> seg(n);
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        seg.update(i, Lazy(0, sum));
    }
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            long long k, u; cin >> k >> u;
            --k;
            seg.update(k, n - 1, Lazy(0, u - a[k]));
            a[k] = u;
        }
        else {
            int l, r; cin >> l >> r;
            --l, --r;
            cout << max(0LL, seg.query(l, r).val - (l == 0 ? 0 : seg.query(l - 1, l - 1).val)) << '\n';
        }
    }
}
