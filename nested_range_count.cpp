#include <bits/stdc++.h>
using namespace std;

class Seg {
    public:
    int n;
    vector<int> seg;
    Seg(int _n) {
        n = _n;
        seg = vector<int>(4 * n);
    }
    void update(int i, int l, int r, int idx, int val) {
        if(l == r) {
            seg[i] += val;
            return;
        }
        int mid = (l + r) / 2;
        if(idx <= mid) update(2 * i + 1, l, mid, idx, val);
        else update(2 * i + 2, mid + 1, r, idx, val);
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    int query(int i, int l, int r, int ll, int rr) {
        if(l > r || l > rr || r < ll) return 0;
        if(l >= ll && r <= rr) return seg[i];
        int mid = (l + r) / 2;
        return query(2 * i + 1, l, mid, ll, rr) + query(2 * i + 2, mid + 1, r, ll, rr);
    }
};


int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    vector<int> st;
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i] = x, b[i] = y;
        st.push_back(x);
        st.push_back(y);
    }

    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());
    
    // compression
    int cnt = 0;
    map<int,int> comp;
    for(auto i : st) comp[i] = cnt++;
    for(auto &x : a) x = comp[x];
    for(auto &y : b) y = comp[y];

    vector<int> p(n + 1), q(n + 1);

    sort(ord.begin(), ord.end(), [&](int x, int y) {
        return a[x] < a[y];
    });

    Seg seg(cnt);
    for(int i = 0; i < n;) {
        int j = i + 1;
        while(j < n && a[ord[j]] == a[ord[i]]) j += 1;
        for(int k = i; k < j; k++) {
            seg.update(0, 0, cnt - 1, b[ord[k]], 1);
        }
        for(int k = i; k < j; k++) {
            q[ord[k]] = seg.query(0, 0, cnt - 1, b[ord[k]], cnt - 1) - 1;
        }
        i = j;
    }

    reverse(ord.begin(), ord.end());

    Seg seg2(cnt);

    for(int i = 0; i < n;) {
        int j = i + 1;
        while(j < n && a[ord[j]] == a[ord[i]]) j += 1;
        for(int k = i; k < j; k++) {
            seg2.update(0, 0, cnt - 1, b[ord[k]], 1);
        }
        for(int k = i; k < j; k++) {
            p[ord[k]] = seg2.query(0, 0, cnt - 1, 0, b[ord[k]]) - 1;
        }
        i = j;
    }
    for(int i = 1; i <= n; i++) cout << p[i - 1] << ' ';
    cout << '\n';
    for(int i = 1; i <= n; i++) cout << q[i - 1] << ' ';
    cout << '\n';
}
