#include <bits/stdc++.h>
using namespace std;

#define int long long

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



signed main(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    vector<vector<pair<int,int>>> queries(n);
    for(int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        queries[x].emplace_back(y, i);
    }

    Seg<Lazy> seg(n);
    vector<int> ans(q);

    stack<pair<int,int>> st;
    for(int i = n - 1; i >= 0; i--) {
        int last = i;
        while(!st.empty() && st.top().first < a[i]) {
            seg.update(last + 1, st.top().second, Lazy(0, a[i] - st.top().first));
            last = st.top().second;
            st.pop();
        }
        st.emplace(a[i], last);

        for(auto [j, idx] : queries[i]) {
            ans[idx] = seg.query(i, j).val;
        }
    }
    for(int &i : ans) cout << i << '\n';
}
