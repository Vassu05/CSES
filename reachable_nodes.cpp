#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> deg(n);

    bitset<50001> ans[n];

    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[y].push_back(x);
        deg[x] += 1;
    }

    queue<int> q;

    for(int i = 0; i < n; i++) {
        ans[i].set(i);
        if(deg[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(auto it : g[x]) {
            ans[it] |= ans[x];
            if(!--deg[it]) {
                q.push(it);
            }
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i].count() << ' ';
    cout << '\n';
}
