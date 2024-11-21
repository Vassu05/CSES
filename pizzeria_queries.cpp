#include <bits/stdc++.h>
using namespace std;


template<typename T>
class Seg {
    #define _l 2 * i + 1
    #define _r 2 * i + 2
    public:
    int n;
    T init;
    vector<T> seg;
    T get(T x, T y) {
        return min(x, y);
    }
    Seg(int _n, T init = T()) {
        n = _n;
        this->init = init;
        seg = vector<T> (4 * n, this->init);
    }
    void build(int i, int l, int r, vector<int> &a) {
        if(l == r) {
            seg[i] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(_l, l, mid, a);
        build(_r, mid + 1, r, a);
        seg[i] = get(seg[_l], seg[_r]);
    }
    Seg(vector<T> a, T init = T()) {
        n = a.size();
        this->init = init;
        seg = vector<T> (4 * n, this->init);
        build(0, 0, n - 1, a);
    }
    void update(int i, int l, int r, int idx, T val) {
        if(l == r) {
            seg[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if(idx <= mid) update(_l, l, mid, idx, val);
        else update(_r, mid + 1, r, idx, val);
        seg[i] = get(seg[_l], seg[_r]);
    }
    void update(int idx, T val) { return update(0, 0, n - 1, idx, val); }
    T query(int i, int l, int r, int ll, int rr) {
        if(l > r || l > rr || r < ll) return this->init;
        if(l >= ll && r <= rr) return seg[i];
        int mid = (l + r) / 2;
        return get(query(_l, l, mid, ll, rr), query(_r, mid + 1, r, ll, rr));
    }
    T query(int l, int r) { return query(0, 0, n - 1, l, r); }
    #undef _l
    #undef _r
};


int main(){
    int n, q; cin >> n >> q;
    Seg<long long> left(n, 1e17), right(n, 1e17);
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        left.update(i, a[i] - i);
        right.update(i, a[i] + i);
    }

    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int k, x; cin >> k >> x;
            --k;
            left.update(k, x - k);
            right.update(k, x + k);
        }
        else {
            int k; cin >> k; --k;
            cout << min(left.query(0, k) + k, right.query(k, n - 1) - k) << '\n';
        }
    }
}
