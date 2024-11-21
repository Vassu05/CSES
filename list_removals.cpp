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
        return (x + y);
    }
    Seg(int _n, T init = T()) {
        n = _n;
        this->init = T();
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
        if(l > r || l > rr || r < ll) return 0;
        if(l >= ll && r <= rr) return seg[i];
        int mid = (l + r) / 2;
        return get(query(_l, l, mid, ll, rr), query(_r, mid + 1, r, ll, rr));
    }
    T query(int l, int r) { return query(0, 0, n - 1, l, r); }
    #undef _l
    #undef _r
};


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    Seg<int> seg(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        seg.update(i, 1);
    }
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        int l = 0, r = n;
        while(l < r) {
            int mid = (l + r) / 2;
            if(seg.query(0, mid) >= x) r = mid;
            else l = mid + 1;
        }
        cout << a[l] << ' ';
        seg.update(l, 0);
    }
}
