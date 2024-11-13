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
    vector<int> ord, vis(n);
    auto dfs = [&](auto self, int x) -> void {
        vis[x] = 1;
        for(auto it : g[x]) if(!vis[it]) self(self, it);
        ord.push_back(x);
    };
    auto dfs2 = [&](auto self, int x) -> void {
        vis[x] = 1;
        for(auto it : rev[x]) if(!vis[it]) self(self, it);
    };
    for(int i = 0; i < n; i++) if(!vis[i]) dfs(dfs, i);
    vector<int> r_ord = ord;
    reverse(r_ord.begin(), r_ord.end());
    vector<int> store;
    vis = vector<int> (n, 0);
    for(int i : r_ord) if(!vis[i]){
        dfs2(dfs2, i);
        store.push_back(i);
    }
    if(store.size() == 1) cout << "YES\n";
    else {
        cout << "NO\n";
        cout << store[1] + 1 << ' ' << store[0] + 1 << '\n';
    }
}
