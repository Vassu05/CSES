#include <bits/stdc++.h>
using namespace std;

#define int long long

class Lazy {
    public:
    long long val, lazy, set;
    Lazy() {
        val = lazy = 0;
        set = -1;
    }
    Lazy(long long x) {
        val = x;
        lazy = 0;
        set = -1;
    }
    Lazy(long long x, long long y, long long z) {
        val = x, lazy = y, set = z;
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
        seg = vector<T> (4 * n, Lazy());
    }
    T get(T x, T y) {
        return T(x.val + y.val);
    }
    void pull(int i, int l, int r) {
        if(l > r) return;
        if(seg[i].set != -1) {
            seg[i].val = (r - l + 1) * seg[i].set;
        }
        seg[i].val += (r - l + 1) * seg[i].lazy;
        if(l < r) {
            if(seg[i].set != -1) {
                seg[_l].set = seg[i].set;
                seg[_r].set = seg[i].set;
                seg[_l].lazy = 0;
                seg[_r].lazy = 0;
            }
            seg[_l].lazy += seg[i].lazy;
            seg[_r].lazy += seg[i].lazy;
        }
        seg[i].set = -1;
        seg[i].lazy = 0;
    }
    void update(int i, int l, int r, int ll, int rr, T val) {
        pull(i, l, r);
        if(l > r || l > rr || r < ll) return;
        if(l >= ll && r <= rr) {
            if(val.set != -1) {
                seg[i].set = val.set;
                seg[i].lazy = 0;
            }
            else {
                seg[i].lazy += val.lazy;
            }
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
        if(l >= ll && r <= rr) { 
            return seg[i];
        }
        int mid = (l + r) / 2;
        return get(query(_l, l, mid, ll, rr), query(_r, mid + 1, r, ll, rr));
    }
    T query(int l, int r) { return query(0, 0, n - 1, l, r); }
    T query(int idx) { return query(idx, idx); }
    #undef _l
    #undef _r
};


signed main(){
    int n, q; cin >> n >> q;
    vector<int> a(n); for(int &i : a) cin >> i;

    Seg<Lazy> seg(n);

    for(int i = 0; i < n; i++) {
        seg.update(i, Lazy(0, 0, a[i]));

    }

    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int l, r, val; cin >> l >> r >> val;
            --l, --r;
            seg.update(l, r, Lazy(0, val, -1));
        }
        else if(op == 2){
            int l, r, val; cin >> l >> r >> val;
            --l, --r;
            seg.update(l, r, Lazy(0, 0, val));
        }
        else {
            int l, r; cin >> l >> r;
            --l, --r;
            cout << seg.query(l, r).val << '\n';
        }
    }
}
