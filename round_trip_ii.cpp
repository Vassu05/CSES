#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
    }
    vector<int> vis(n), vis2(n), ans;
    auto dfs = [&](auto self, int x) -> bool {
        ans.push_back(x);
        if(vis[x]) return true;
        vis[x] = vis2[x] = 1;
        for(auto it : g[x]) { 
            if(vis[it]) return self(self, it);
            else if(vis2[it]) continue;
            if(self(self,it)) return true;
        }
        vis[x] = 0;
        ans.pop_back();
        return false;
    };
    for(int i = 0; i < n; i++) if(!vis2[i] && dfs(dfs,i)) {
        reverse(ans.begin(), ans.end());
        while(ans[0] != ans.back()) ans.pop_back();
        reverse(ans.begin(), ans.end());
        if((int)ans.size() <= 2) continue;
        cout << ans.size() << '\n';
        for(int it : ans) cout << it + 1 << ' ';
        cout << '\n';
        return 0;
    }
    cout << "IMPOSSIBLE\n";
}
