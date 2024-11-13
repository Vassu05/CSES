#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n), rev(n);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[--x].push_back(--y);
        rev[y].push_back(x);
    }
    vector<int> ord, vis(n), ans(n);
    int c = 1;
    auto dfs = [&](auto self, int x) -> void {
        vis[x] = 1;
        for(auto it : g[x]) if(!vis[it]) self(self, it);
        ord.push_back(x);
    };
    auto dfs2 = [&](auto self, int x) -> void {
        vis[x] = 1;
        ans[x] = c;
        for(auto it : rev[x]) if(!vis[it]) self(self, it);
    };
    for(int i = 0; i < n; i++) if(!vis[i]) dfs(dfs, i);
    reverse(ord.begin(), ord.end());
    vis = vector<int> (n);

    for(int i : ord) if(!vis[i]){
        dfs2(dfs2, i);
        c += 1;
    }
    cout << c - 1 << '\n';
    for(int i : ans) cout << i << ' ';
    cout << '\n';
}
