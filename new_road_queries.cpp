#include <bits/stdc++.h>
using namespace std;

class DSU {
    public:
    int n;
    vector<int> par, rank;
    DSU(int _n) {
        n = _n;
        par = vector<int> (n);
        rank = vector<int> (n);
        for(int i = 0; i < n; i++) par[i] = i, rank[i] = 1;
    }
    int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
    bool add(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        rank[x] += rank[y];
        par[y] = x;
        return true;
    }
    bool connected(int x, int y) { return find(x) == find(y); }
};

const int N = 200100, LOG = 20;
vector<pair<int,int>> g[N];
int depth[N], par[N][LOG], val[N][LOG];
int n, m, q;

void init(int x, int y) {
    par[x][0] = y;
    for(auto [it, w] : g[x]) if(it != y) {
        depth[it] = depth[x] + 1;
        val[it][0] = w;
        init(it, x);
    }
}

int LCA(int x, int y) {
    if(depth[x] < depth[y]) swap(x, y);
    int d = depth[x] - depth[y];
    int ans = 0;
    for(int i = 0; i < LOG; i++) if(d >> i & 1) { 
        ans = max(ans, val[x][i]);
        x = par[x][i];   
    }
    assert(depth[x] == depth[y]);
    if(x == y) return ans;
    for(int j = LOG - 1; j >= 0; j--) {
        if(par[x][j] != par[y][j]) {
            ans = max(ans, val[x][j]);
            ans = max(ans, val[y][j]);
            x = par[x][j];
            y = par[y][j];
        }
    }
    ans = max(ans, val[x][0]);
    ans = max(ans, val[y][0]);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    DSU dsu(n);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        if(dsu.add(x, y)) {
            g[x].emplace_back(y, i);
            g[y].emplace_back(x, i);
        }
    }
    for(int i = 0; i < n; i++) depth[i] = -1;
    for(int i = 0; i < n; i++) if(depth[i] == -1) {
        depth[i] = 0;
        init(i, i);
    }
    for(int j = 1; j < LOG; j++) {
        for(int i = 0; i < n; i++) {
            par[i][j] = par[par[i][j - 1]][j - 1];
            val[i][j] = max(val[i][j - 1], val[par[i][j - 1]][j - 1]);
        }
    }

    while(q--) {
        int x, y; cin >> x >> y;
        --x, --y;
        if(!dsu.connected(x, y)) {
            cout << -1 << '\n';
            continue;
        }
        cout << (x == y ? 0 : LCA(x, y) + 1) << '\n';
    }
}
