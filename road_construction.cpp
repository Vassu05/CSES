#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<int> par(n), rank(n, 1);
    iota(par.begin(), par.end(), 0);
    int mx = 1, count = n;
    auto find = [&](auto self, int x) -> int {
        return (par[x] == x ? x : par[x] = self(self, par[x]));
    };

    auto merge = [&](int x, int y) -> bool {
        x = find(find, x), y = find(find, y);
        if(x != y) {
            rank[x] += rank[y];
            par[y] = x;
            mx = max(mx, rank[x]);
            return true;
        }
        return false;
    };
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        count -= merge(x, y);
        cout << count << ' ' << mx << '\n';
    }
}
