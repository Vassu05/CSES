#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[--x].push_back(--y);
        g[y].push_back(x);
    }
    vector<int> ans(n, -1);
    auto check = [&](int x) -> bool {
        ans[x] = 1;
        queue<int> q;
        q.push(x);
        while(!q.empty()) {
            x = q.front(); q.pop();
            for(auto it : g[x]) {
                if(ans[it] == -1) {
                    ans[it] = 3 - ans[x];
                    q.push(it);
                }
                else {
                    if(ans[it] != 3 - ans[x]) return false;
                }
            }
        }
        return true;
    };
    for(int i = 0; i < n; i++) if(ans[i] == -1) {
        if(!check(i)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    for(int i : ans) cout << i << ' ';
    cout << '\n';
}
