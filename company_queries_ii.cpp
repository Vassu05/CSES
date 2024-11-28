#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q; cin >> n >> q;
    vector<int> depth(n);
    int LOG = 20;
    vector<vector<int>> par(n, vector<int> (LOG));
    for(int i = 1; i < n; i++) {
        int x; cin >> x;
        --x;
        depth[i] = depth[x] + 1;
        par[i][0] = x;
    }
    for(int i = 1; i < LOG; i++) {
        for(int j = 0; j < n; j++) par[j][i] = par[par[j][i - 1]][i - 1];
    }

    auto LCA = [&](int x, int y) -> int {
        if(depth[x] < depth[y]) swap(x, y);
        int diff = depth[x] - depth[y];
        for(int i = 0; i < LOG; i++) if(diff >> i & 1) x = par[x][i];
        if(x == y) return x;
        for(int j = LOG - 1; j >= 0; j--) if(par[x][j] != par[y][j]) x = par[x][j], y = par[y][j];
        return par[x][0];
    };

    while(q--) {
        int x, y; cin >> x >> y;
        --x, --y;
        cout << LCA(x, y) + 1 << '\n';
    }
}
