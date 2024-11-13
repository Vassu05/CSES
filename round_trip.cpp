#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> ans, vis(n);
    auto dfs = [&](auto self, int x, int y) -> bool {
        vis[x] = 1;
        ans.push_back(x);
        for(auto it : g[x]) if(it != y) {
            if(vis[it]) {
                ans.push_back(it);
                return true;
            }
            else {
                if(self(self, it, x)) return true;
            }
        }
        ans.pop_back();
        return false;
    };
    for(int i = 0; i < n; i++) if(!vis[i]){
        if(dfs(dfs, i, i)) {
            int idx = 0;
            while(ans[idx] != ans.back()) idx += 1;
            cout << ans.size() - idx << '\n';
            for(int j = idx; j < (int)ans.size(); j++) cout << ans[j] + 1 << ' ';
            cout << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}
