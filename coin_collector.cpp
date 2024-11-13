#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    vector<vector<int>> g(n), rev(n);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[--x].push_back(--y);
        rev[y].push_back(x);
    }
    vector<int> vis(n), ord;
    auto dfs = [&](auto self, int x) -> void {
        vis[x] = 1;
        for(auto it : g[x]) if(!vis[it]) self(self, it);
        ord.push_back(x);
    };
    for(int i = 0; i < n; i++) if(!vis[i]) dfs(dfs, i);
    reverse(ord.begin(), ord.end());
    vis = vector<int> (n);
    vector<int> comp(n);
    int c = 0;
    auto dfs2 = [&](auto self, int x) -> void {
        vis[x] = 1;
        comp[x] = c;
        for(int it : rev[x]) if(!vis[it]) self(self, it);
    };
    for(int i : ord) if(!vis[i]) {
        dfs2(dfs2, i);
        c += 1;
    }
    vector<vector<int>> new_g(c);
    vector<int> sum(c);
    for(int i = 0; i < n; i++) {
        sum[comp[i]] += a[i];
        for(auto it : g[i]) if(comp[i] != comp[it]) {
            new_g[comp[i]].push_back(comp[it]);
        }
    }
    vis = vector<int> (n, 0);
    auto dfs_final = [&](auto self, int x) -> int {
        if(vis[x] > 0) return vis[x];
        vis[x] = sum[x];
        int mx = 0;
        for(auto it : new_g[x]) {
            mx = max(mx, self(self, it));
        }
        vis[x] += mx;
        return vis[x];
    };
    int ans = 0;
    for(int i = 0; i < c; i++)  { 
        ans = max(ans, dfs_final(dfs_final, i));
    }
    cout << ans << '\n';
}

