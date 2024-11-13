#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        --x, --y;
        g[x].emplace_back(y, z);
    }
    vector<priority_queue<int>> pq(n);
    priority_queue<pair<int,int>> q;
    auto give = [&](int x, int y) -> bool {
        if(pq[x].top() > y) {
            pq[x].pop();
            pq[x].push(y);
            return true;
        }
        return false;
    };

    for(int i = 0; i < n; i++) for(int j = 0; j < k; j++) pq[i].push(1e18);
    give(0, 0);
    q.emplace(0, 0);
    while(!q.empty()) {
        auto [d, x] = q.top(); q.pop();
        d = -d;
        if(pq[x].top() < d) continue;
        for(auto [v, w] : g[x]) {
            if(give(v, w + d)) {
                q.emplace(-w-d, v);
            }
        }
    }
    vector<int> ans;
    while(!pq[n - 1].empty()) {
        ans.push_back(pq[n - 1].top());
        pq[n - 1].pop();
    }
    reverse(ans.begin(), ans.end());
    for(int i : ans) cout << i << ' ';
    cout << '\n';
}
