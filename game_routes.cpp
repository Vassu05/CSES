#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> in(n);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        in[y] += 1;
    }
    vector<int> ans(n);
    int mod = 1e9 + 7;
    ans[0] = 1;
    queue<int> q;
    for(int i = 0; i < n; i++) if(in[i] == 0) q.push(i);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(auto it : g[x]) {
            ans[it] += ans[x];
            if(ans[it] >= mod) ans[it] -= mod;
            if(!--in[it]) q.push(it);
        }
    }
    cout << ans[n - 1] << '\n';
}
