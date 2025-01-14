#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 1;

int n, m, Q;
vector<int> g[N], rev[N];
bitset<N> ans[N];

int main(){
    cin >> n >> m >> Q;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        rev[y].push_back(x);
    }

    vector<int> vis(n);
    vector<int> ord;
    auto topo = [&](auto self, int x) -> void {
        vis[x] = 1;
        for(auto it : g[x]) if(!vis[it]) self(self, it);
        ord.push_back(x);
    };

    for(int i = 0; i < n; i++) if(!vis[i]) topo(topo, i);
    reverse(ord.begin(), ord.end());
    vector<int> comp(n);
    int c = 0;

    auto dfs = [&](auto self, int x) -> void {
        vis[x] = 1;
        comp[x] = c;
        ans[comp[x]].set(x);
        for(auto it : rev[x]) if(!vis[it]) self(self, it);
    };

    vis = vector<int> (n, 0);
    for(int i : ord) if(!vis[i]) dfs(dfs, i), c += 1;
    vector<vector<int>> ng(c);
    vector<int> deg(c);
    for(int i = 0; i < n; i++) {
        for(auto it : g[i]) if(comp[i] != comp[it]) { 
            ng[comp[it]].push_back(comp[i]);
            deg[comp[i]] += 1;
        }
    }
    queue<int> q;
    for(int i = 0; i < c; i++) {
        if(deg[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(auto it : ng[x]) {
            ans[it] |= ans[x];
            if(!--deg[it]) q.push(it);
        }
    }

    while(Q--) {
        int x, y; cin >> x >> y;
        --x, --y;
        cout << (ans[comp[x]][y] ? "YES\n" : "NO\n");
    }
}
