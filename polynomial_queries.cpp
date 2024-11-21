#include <bits/stdc++.h>
using namespace std;

#define int long long

class Lazy {
    public:
    long long val, start, count;
    Lazy() {
        val = start = count = 0;
    }
    Lazy(long long x) {
        val = x;
        start = 0;
        count = 0;
    }
    Lazy(long long x, long long y, long long z) {
        val = x, start = y, count = z;
    }
};

// x      x + 1       x + 2       x + 3          x + r - l
// y      y + 1       y + 2       y + 3          y + r - l
// z      z + 1       z + 2       z + 3          z + r - l
// x + y  x + y + 2   x + y + 4   x + y + 6
//

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
        return T(x.val + y.val);
    }
    void pull(int i, int l, int r) {
        if(l > r) return;
        seg[i].val += seg[i].start * (r - l + 1);
        seg[i].val += seg[i].count * (r - l + 1) * (r - l) / 2;
        if(l < r && seg[i].count > 0) {
            int mid = (l + r) / 2;
            seg[_l].start += seg[i].start;
            seg[_l].count += seg[i].count;
            seg[_r].start += seg[i].start + seg[i].count * (mid - l + 1);
            seg[_r].count += seg[i].count;
        }
        seg[i].start = 0;
        seg[i].count = 0;
    }
    void update(int i, int l, int r, int ll, int rr, int start) {
        pull(i, l, r);
        if(l > r || l > rr || r < ll) return;
        if(l >= ll && r <= rr) {
            seg[i].start += start;
            seg[i].count += 1;
            pull(i, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(_l, l, mid, ll, rr, start);
        update(_r, mid + 1, r, ll, rr, start + max(0LL, min(rr, mid) - max(l, ll) + 1));
        seg[i] = get(seg[_l], seg[_r]);
    }
    void update(int l, int r, int val) { update(0, 0, n - 1, l, r, val); }
    void update(int idx, int val) { update(idx, idx, val); }
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



int32_t main(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    Seg<Lazy> seg(n);
    for(int i = 0; i < n; i++) {
        seg.update(i, i, a[i]);
    }
    while(q--) {
        int op, l, r; cin >> op >> l >> r;
        --l, --r;
        if(op == 1) {
            seg.update(l, r, 1);
        }
        else {
            cout << seg.query(l, r).val << '\n';
        }
    }
}
