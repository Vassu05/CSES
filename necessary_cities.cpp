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
    vector<int> ans, disc(n, -1), low(n);
    int time = 0;
    auto dfs = [&](auto self, int x, int y) -> void {
        disc[x] = low[x] = time++;
        bool imp = false;
        int child = 0;
        for(auto it : g[x]) if(it != y) {
            if(disc[it] == -1) {
                child += 1;
                self(self, it, x);
                low[x] = min(low[x], low[it]);

                if(y != -1 && low[it] >= disc[x]) {
                    imp = true;
                }
            }
            else low[x] = min(low[x], disc[it]);
        }
        if(y == -1 && child > 1) imp = true;
        if(imp) ans.push_back(x);
    };

    dfs(dfs, 0, -1);

    cout << ans.size() << '\n';
    for(int i : ans) cout << i + 1 << ' ';
    cout << '\n';
}
