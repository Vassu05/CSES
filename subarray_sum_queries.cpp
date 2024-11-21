#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    long long left, right, mx, total;
    Node() {
        left = 0, right = 0; total = -1e17;
        mx = -1e17;
    }
    Node(int x) {
        left = right = mx = total = x;
    }
};

template<typename T>
class Seg {
    #define _l 2 * i + 1
    #define _r 2 * i + 2
    public:
    int n;
    T init;
    vector<T> seg;
    T get(T x, T y) {
        T ans;
        ans.left = max(x.left, x.total + y.left);
        ans.right = max(y.right, y.total + x.right);
        ans.total = x.total + y.total;
        ans.mx = max({x.mx, y.mx, x.right + y.left});
        return ans;
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
    Seg<Node> seg(n, -1e17);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        seg.update(i, Node(x));
    }
    while(q--) {
        int idx, val; cin >> idx >> val;
        --idx;
        seg.update(idx, Node(val));
        cout << max(0LL, seg.seg[0].mx) << '\n';
    }
}
