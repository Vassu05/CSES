#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 118;
int vis[N], sizes[N], d[N];
vector<int> g[N];
int n, k;

int find_sizes(int x, int y) {
    sizes[x] = 1;
    for(auto it : g[x]) if(it != y && !vis[it]) {
        sizes[x] += find_sizes(it, x);
    }
    return sizes[x];
}

int find_centroid(int x, int y, int req) {
    for(auto it : g[x]) if(it != y && !vis[it] && sizes[it] >= req) return find_centroid(it, x, req);
    return x;
}

long long calculate(int x, int y, bool add, int depth) {
    if(depth > k) return 0;
    long long ans = 0;
    if(add) d[depth] += 1;
    else {
        ans += d[k - depth];
    }
    for(auto it : g[x]) if(it != y && !vis[it]) ans += calculate(it, x, add, depth + 1);
    return ans;
}


long long dfs(int x, int y) {
    int size = find_sizes(x, y);
        int centroid = find_centroid(x, y, size / 2);
        vis[centroid] = 1;
        long long ans = 0;
        for(auto it : g[centroid]) if(!vis[it]) {
            ans += calculate(it, centroid, false, 1);
            ans += calculate(it, centroid, true, 1);
        }
        ans += d[k];
        for(int j = 1; d[j] > 0; j++) d[j] = 0;
        for(auto it : g[centroid]) if(!vis[it]) ans += dfs(it, centroid);
        return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i = 0; i <= n + 10; i++) vis[i] = 0;

    cout << dfs(0, 0);
}
