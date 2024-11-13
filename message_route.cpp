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
    vector<int> par(n, -1);
    par[0] = -2;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(auto it : g[x]) if(par[it] == -1) {
            par[it] = x;
            q.push(it);
        }
    }
    vector<int> ans;
    int now = n - 1;
    while(now != 0) {
        if(now == -1) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        ans.push_back(now);
        now = par[now];
    }
    ans.push_back(0);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int i : ans) cout << i + 1 << ' ';
    cout << '\n';
}
