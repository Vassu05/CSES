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
        return max(x, y);
    }
    Seg () {}
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

const int LOG = 20;
const int N = 2e5 + 118;
int par[N][LOG], values[N];

class HLD {
    int n, assign;
    vector<int> g[N];
    int sizes[N], index[N], prevUnMarked[N], depth[N];
    Seg<int> seg;
    public:
    HLD(int _n) {
        n = _n;
        assign = 0;
        for(int i = 0; i < n; i++) sizes[i] = index[i] = prevUnMarked[i] = depth[i] = 0;
        seg = Seg<int> (n);
    }
    void addEdge(int x, int y) {
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int preCalc(int x, int y) {
        sizes[x] = 1;
        par[x][0] = y;
        for(int i = 1; i < LOG; i++) par[x][i] = par[par[x][i - 1]][i - 1];
        for(auto it : g[x]) if(it != y) { 
            depth[it] = depth[x] + 1;
            sizes[x] += preCalc(it, x);
        }
        return sizes[x];
    }
    // mark the edge which carries the most weight
    void dfs(int x, int y) {
        index[x] = assign++;
        seg.update(index[x], values[x]);
        if((int)g[x].size() == 0) return;
        if((int)g[x].size() == 1 && x != 0) return;
        int now = -1;
        for(int it : g[x]) if(it != y) {
            if(now == -1 || sizes[it] > sizes[now]) now = it;
        }
        prevUnMarked[now] = prevUnMarked[x];
        dfs(now, x);
        for(auto it : g[x]) if(it != y && it != now) {
            prevUnMarked[it] = it;
            dfs(it, x);
         }
    }
    void init() {
        preCalc(0, 0);
        prevUnMarked[0] = 0;
        dfs(0, 0);
    }
    void update(int x, int val) {
        seg.update(index[x], val);
        values[x] = val;
    }
    int LCA(int x, int y) {
        if(depth[x] < depth[y]) swap(x, y);
        int diff = depth[x] - depth[y];
        for(int j = 0; j < LOG; j++) if(diff >> j & 1) x = par[x][j];
        if(x == y) return x;
        for(int j = LOG - 1; j >= 0; j--) if(par[x][j] != par[y][j]) x = par[x][j], y = par[y][j];
        return par[x][0];
    }
    int query(int x, int y) {
        int lca = LCA(x, y);
        int ans = 0;
        for(auto it : { x, y }) {
            int now = it;
            while(depth[now] >= depth[lca]) {
                if(depth[prevUnMarked[now]] < depth[lca]) {
                    ans = max(ans, seg.query(index[now] - (depth[now] - depth[lca]), index[now]));
                    break;
                }
                if(prevUnMarked[now] == now) {
                    ans = max(ans, values[now]);
                    if(!now) break;
                    now = par[now][0];
                    continue;
                }
                ans = max(ans, seg.query(index[prevUnMarked[now]], index[now]));
                now = prevUnMarked[now];
                if(now == 0) break;
                now = par[now][0];
            }
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> values[i];
    HLD hld(n);
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        hld.addEdge(x, y);
    }
    hld.init();

    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int s, x; cin >> s >> x;
            --s;
            hld.update(s, x);
        }
        else {
            int a, b; cin >> a >> b;
            --a, --b;
            cout << hld.query(a, b) << '\n';
        }
    }
    cout << '\n';
}
