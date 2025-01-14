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

    vector<int> disc(n, -1), low(n);
    int time = 0;

    vector<pair<int,int>> ans;

    auto dfs = [&](auto dfs, int x, int y) -> void {
        disc[x] = time++;
        low[x] = disc[x];
        for(auto it : g[x]) if(y != it) {
            if(disc[it] == -1) {
                dfs(dfs, it, x);
                low[x] = min(low[x], low[it]);
                if(low[it] > disc[x]) {
                    ans.emplace_back(x, it);
                }
            }
            else low[x] = min(low[x], disc[it]);
        }
    };

    for(int i = 0; i < n; i++) if(disc[i] == -1) dfs(dfs, i, i);

    cout << ans.size() << '\n';
    for(auto [x, y] : ans) {
        cout << x + 1 << ' ' << y + 1 << '\n';
    }
}
