#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> g(n, vector<int> (n, 1e17));
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        --x, --y;
        g[x][y] = min(g[x][y], z);
        g[y][x] = min(g[y][x], z);
    }
    for(int i = 0; i < n; i++) g[i][i] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) for(int k = 0; k < n; k++) {
            g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
        }
    }
    while(q--) {
        int x, y; cin >> x >> y;
        int ans = g[--x][--y];
        cout << (ans < 1e17 ? ans : -1) << '\n';
    }
}
