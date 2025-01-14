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
    friend istream &operator>>(istream &is, Edge &edge) {
        cin >> edge.x >> edge.y >> edge.rem >> edge.cost;
        return is;
    }
};

class Flow {
    public:
    int n;
    vector<Edge> edges;
    vector<vector<int>> g;
    Flow(int _n) : n(_n) {
        g = vector<vector<int>> (n);
    }
    void addEdge(int x, int y, int rem, int cost) {
        edges.push_back(Edge(x, y, rem, cost));
        edges.push_back(Edge(y, x, 0, -cost));
        g[x].push_back(edges.size() - 2);
        g[y].push_back(edges.size() - 1);
    }
    pair<int,int> minCost(int start, int end) {
        int total_cost = 0, total_flow = 0;
        int inf = 1e9;
        while(true) {
            queue<pair<int,int>> q;
            q.push({ start, 0 });
            vector<int> flow(n), cost(n);
            vector<int> par(n, -1);
            for(int i = 0; i < n; i++) cost[i] = inf;
            flow[start] = inf;
            cost[start] = 0;
            
            while(!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                if(cost[x] != y) continue;
                for(auto it : g[x]) {
                    Edge &curr = edges[it];
                    if(curr.rem > 0 && cost[curr.y] > cost[curr.x] + curr.cost) {
                        cost[curr.y] = cost[curr.x] + curr.cost;
                        flow[curr.y] = min(flow[curr.x], curr.rem);
                        par[curr.y] = it;
                        q.emplace(curr.y, cost[curr.y]);
                    }
                }
            }
            if(cost[end] == inf) break;
            total_flow += flow[end];
            total_cost += flow[end] * cost[end];

            int now = end;
            while(now != start) {
                int edge_idx = par[now];
                edges[edge_idx].rem -= flow[end];
                edges[edge_idx ^ 1].rem += flow[end];
                now = edges[edge_idx].x;
            }
        }
        return { total_flow, total_cost };
    }
};

int main(){
    int n, m, k; cin >> n >> m >> k;
    Flow flow(n + 1);
    for(int i = 0; i < m; i++) {
        int x, y, rem, cost; cin >> x >> y >> rem >> cost;
        flow.addEdge(x, y, rem, cost);
    }
    flow.addEdge(0, 1, k, 0);
    auto [maxFlow, ans] = flow.minCost(0, n);
    cout << (maxFlow == k ? ans : -1) << '\n';
}
