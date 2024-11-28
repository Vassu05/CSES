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

    vector<int> dist(n);

    auto bfs = [&](int x) -> void {
        queue<int> q;
        q.push(x);
        dist = vector<int> (n, 1e9);
        dist[x] = 0;
        while(!q.empty()) {
            int y = q.front(); q.pop();
            for(auto it : g[y]) if(dist[it] > dist[y] + 1) {
                dist[it] = dist[y] + 1;
                q.push(it);
            }
        }
    };

    bfs(0);
    bfs(max_element(dist.begin(), dist.end()) - dist.begin());
    auto d1 = dist;
    bfs(max_element(dist.begin(), dist.end()) - dist.begin());
    auto d2 = dist;
    for(int i = 0; i < n; i++) cout << max(d1[i], d2[i]) << ' ';
    cout << '\n';
}
