#include <bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int x, y, rem, cost;
    Edge(int x, int y, int rem, int cost) {
        this->x = x;
        this->y = y;
        this->rem = rem;
        this->cost = cost;
    }
    Edge() {}
};

class Flow {
    public:
    int n;
    vector<Edge> edges;
    vector<vector<int>> g;
    Flow(int _n) {
        n = _n;
        g = vector<vector<int>> (n);
    }
    void addEdge(int x, int y, int rem, int cost) {
        edges.push_back(Edge(x, y, rem, cost));
        edges.push_back(Edge(y, x, 0, -cost));
        g[x].push_back(edges.size() - 2);
        g[y].push_back(edges.size() - 1);
    }
    pair<int,int> minCost(int start, int end) {
        int inf = 1e9;
        int maxFlow = 0, total = 0;
        while(true) {
            vector<int> par(n, -1);
            vector<int> flow(n, 0), cost(n, inf);
            flow[start] = inf;
            cost[start] = 0;
            queue<pair<int,int>> q;
            q.emplace(start, 0);
            while(!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                if(cost[x] != y) continue;
                for(auto it : g[x]) {
                    Edge now = edges[it];
                    if(now.rem > 0 && cost[now.y] > cost[now.x] + now.cost) {
                        flow[now.y] = min(flow[now.x], now.rem);
                        cost[now.y] = cost[now.x] + now.cost;
                        par[now.y] = it;
                        q.emplace(now.y, cost[now.y]);
                    }
                }
            }
            if(cost[end] == inf) break;
            total += flow[end] * cost[end];
            maxFlow += flow[end];

            int now = end;
            while(now != start) {
                int p = par[now];
                edges[p].rem -= flow[end];
                edges[p ^ 1].rem += flow[end];
                now = edges[p].x;
            }
        }

        return { maxFlow, total };

    }
};

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n + 1, vector<int> (n + 1));
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> a[i][j];
    Flow flow(2 * n + 2);
    for(int i = 1; i <= n; i++) {
        flow.addEdge(0, i, 1, 0);
        flow.addEdge(n + i, n + n + 1, 1, 0);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            flow.addEdge(j, n + i, 1, a[i][j]);
        }
    }
    auto [mxFlow, ans] = flow.minCost(0, n + n + 1);
    cout << ans << '\n';
    vector<int> res(n + 1);
    for(auto it : flow.edges) {
        if(it.x >= 1 && it.x <= n && it.cost > 0 && it.rem == 0) {
            res[it.y - n] = it.x;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << i << ' ' << res[i] << '\n';
    }
}
