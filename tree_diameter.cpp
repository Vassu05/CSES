#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> dist;

    auto bfs = [&](int x) -> void {
        dist = vector<int> (n, 1e9);
        dist[x] = 0;
        queue<int> q;
        q.push(x);
        while(!q.empty()) {
            int x = q.front(); q.pop();
            for(auto it : g[x]) if(dist[it] > dist[x] + 1) {
                dist[it] = dist[x] + 1;
                q.push(it);
            }
        }
    };

    bfs(0);
    auto d1 = dist;
    int mx = 0;
    for(int i = 1; i < n; i++) if(dist[i] > dist[mx]) mx = i;
    bfs(mx);
    cout << *max_element(dist.begin(), dist.end()) << '\n';
}
