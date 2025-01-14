#include <bits/stdc++.h>
using namespace std;
int main(){
    // Let's take a graph which has only one component
    // assume that it is a tree
    // number of possible eulerian subgraphs is only one, that is we have to remove all the edges
    // because, no matter what we do, trees always contain leaves and degree of leaves is always one when there are more than 1 node in the tree
    // so the trivial case is to remove all the edges and the answer is one.
    // now say there is a backedge, i.e., our n-node component contains exactly n edges
    // which means our graph contains exactly one cycle
    // 1. we can either choose to remove all edges
    // 2. we can honour the cycle and remove the rest of the edges
    // both the cases will give a valid eulerian subgraph
    // so let's say we have more than 1 back edge
    // we can always honour a subset of these back edges and force form a valid eulerian subgraph
    // to prove it, we should note that a backedge will always end at a non-leaf node which definitely has a child that is not a backedge, so we can choose to remove it to satisfy degree parity
    // hence total eulerian subgraphs is pow(2, number of back edges) = pow(2, m - (n - 1))

    // so for multiple components
    // PI(pow(2, number of edges in component - (number of vertices in the component) + 1))
    // pow(2, sum(number of edges) - sum(number of vertices) + number of components)
    // pow(2, m - n + cc)
    // pow(2, m - (n - cc))

    int n, m; cin >> n >> m;
    // All we have to do is find the number of components

    vector<int> par(n);
    iota(par.begin(), par.end(), 0);
    auto find = [&](auto self, int x) -> int { return par[x] == x ? x : par[x] = self(self, par[x]); };
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        x = find(find, x), y = find(find, y);
        if(x != y) par[x] = y;
    }
    int components = 0;
    for(int i = 0; i < n; i++) components += par[i] == i;

    int mod = 1e9 + 7;
    auto power = [&](int x, int y) -> int {
        int ans = 1;
        for(; y; y >>= 1, x = 1LL * x * x % mod) if(y & 1) ans = 1LL * ans * x % mod;
        return ans;
    };

    cout << power(2, m - (n - components)) << '\n';
}
