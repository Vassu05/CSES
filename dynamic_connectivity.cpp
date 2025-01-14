#include <bits/stdc++.h>
using namespace std;

class DSU {
    public:
    int n;
    vector<int> par, rank;
    vector<pair<int,int>> history;
    int components;
    DSU() {}
    DSU(int _n) {
        n = _n;
        components = n;
        par = vector<int> (n);
        rank = vector<int> (n);
        for(int i = 0; i < n; i++) par[i] = i, rank[i] = 1;
    }
    int find(int x) { return par[x] == x ? x : find(par[x]); }
    bool add(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        components -= 1;
        if(rank[x] < rank[y]) {
            swap(x, y);
        }
        history.emplace_back(y, par[y]);
        history.emplace_back(x, rank[y]);
        par[y] = x;
        rank[x] += rank[y];
        return true;
    }
    bool connected(int x, int y) { return find(x) == find(y); }
    void rollback() {
        auto [x, y] = history.back();
        rank[x] -= y;
        history.pop_back();
        tie(x, y) = history.back();
        par[x] = y;
        history.pop_back();
        components += 1;
    }
    void rollback(int until) {
        while((int)history.size() > until) {
            rollback();
        }
    }
};


DSU dsu;

class Seg {
    public:
    int n;
    vector<vector<pair<int,int>>> seg;
    Seg(int _n) {
        n = _n;
        seg = vector<vector<pair<int,int>>> (4 * n);
    }
    void add(int i, int l, int r, int ll, int rr, pair<int,int> p) {
        if(l > r || l > rr || r < ll) return;
        if(l >= ll && r <= rr) {
            seg[i].push_back(p);
            return;
        }
        int mid = (l + r) / 2;
        add(2 * i + 1, l, mid, ll, rr, p);
        add(2 * i + 2, mid + 1, r, ll, rr, p);
    }

    void dfs(int i, int l, int r) {

        int curr = dsu.history.size();

        for(auto [x, y] : seg[i]) {
            dsu.add(x, y);
        }

        if(l == r) {
            cout << dsu.components << ' ';
        }
        else {
            int mid = (l + r) / 2;
            dfs(2 * i + 1, l, mid);
            dfs(2 * i + 2, mid + 1, r);
        }

        dsu.rollback(curr);
    }
};

int main(){
    int n, m, k; cin >> n >> m >> k;
    dsu = DSU(n);
    Seg seg(k + 1);
    map<pair<int,int>, int> mp;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        if(x > y) swap(x, y);
        mp[{x, y}] = 0;
    }

    for(int i = 0; i < k; i++) {
        int op, x, y; cin >> op >> x >> y;
        --x, --y;
        if(x > y) swap(x, y);
        if(op == 1) {
            mp[{x, y}] = i + 1;
        }
        else {
            seg.add(0, 0, k, mp[{x, y}], i, {x, y});
            mp.erase({x, y});
        }
    }

    for(auto it : mp) {
        seg.add(0, 0, k, it.second, k, it.first);
    }

    seg.dfs(0, 0, k);

    cout << '\n';
}
