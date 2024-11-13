#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        --x, --y;
        g[x].emplace_back(y, z);
    }
    priority_queue<pair<int,int>> q;
    q.emplace(0, 0);
    vector<int> a(n, 1e18), b(n, 0), c(n, 1e18), d(n, 0);
    a[0] = 0;
    b[0] = 1;
    c[0] = 0;
    d[0] = 0;

    int mod = 1e9 + 7;
    while(!q.empty()) {
        auto [x, y] = q.top(); q.pop();
        x = -x;
        if(a[y] != x) continue;
        for(auto [v, w] : g[y]) {
            if(a[v] > x + w) {
                a[v] = x + w;
                b[v] = 0, c[v] = 1e18, d[v] = 0;
                q.emplace(-a[v], v);
            }
            if(a[v] == x + w) {
                b[v] += b[y];
                if(b[v] >= mod) b[v] -= mod;
                c[v] = min(c[v], 1 + c[y]);
                d[v] = max(d[v], 1 + d[y]);
            }
        }
    }
    cout << a[n - 1] << ' ' << b[n - 1] << ' ' << c[n - 1] << ' ' << d[n - 1] << '\n';
}
