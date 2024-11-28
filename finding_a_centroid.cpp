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

    vector<bool> ans(n, true);

    auto dfs = [&](auto self, int x, int y) -> int {
        int now = 1;
        for(auto it : g[x]) if(it != y) {
            int got = self(self, it, x);
            ans[x] = (ans[x] && (got <= (n / 2)));
            now += got;
        }
        ans[x] = (ans[x] && ((n - now) <= (n / 2)));
        return now;
    };

    dfs(dfs, 0, 0);

    for(int i = 0; i < n; i++) if(ans[i]) {
        cout << i + 1 << '\n';
        return 0;
    }
}
