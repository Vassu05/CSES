#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> child(n, 0), sz(n, 0), ans(n, 0);

    auto dfs = [&](auto self, int x, int y) -> int {
        sz[x] = 1;
        for(auto it : g[x]) if(it != y) {
            sz[x] += self(self, it, x);
            child[x] += child[it] + sz[it];
        }
        return sz[x];
    };

    dfs(dfs, 0, 0);

    auto dfs2 = [&](auto self, int x, int y, int z) -> void {
        z -= 2 * sz[x];
        ans[x] = z;
        for(auto it : g[x]) if(it != y) self(self, it, x, z + n);
    };

    dfs2(dfs2, 0, 0, child[0] + 2 * n);

    for(int i : ans) cout << i << ' ';
    cout << '\n';
}
