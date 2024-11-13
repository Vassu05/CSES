#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[y].push_back(x);
    }
    vector<int> ans, vis(n), vis2(n);
    bool flag = false;
    auto dfs = [&](auto self, int x) {
        vis[x] = 1;
        vis2[x] = 1;
        for(auto it : g[x]) {
            if(vis2[it]) {
                flag = true;
                return;
            }
            else if(vis[it]) continue;
            self(self, it);
        }
        vis2[x] = 0;
        ans.push_back(x);

    };
    for(int i = 0; i < n; i++) if(!vis[i]) dfs(dfs, i);
    if(flag) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int i : ans) cout << i + 1 << ' ';
    cout << '\n';
}
