#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<vector<int>> dp(n, vector<int> (2));

    auto dfs = [&](auto self, int x, int y) -> void {
        vector<pair<int,int>> temp;
        int sum = 0;
        for(auto it : g[x]) if(it != y) {
            self(self, it, x);
            dp[x][0] += max(dp[it][0], dp[it][1]);
            temp.emplace_back(dp[it][0], dp[it][1]);
            sum += max(dp[it][0], dp[it][1]);
        }
        for(auto [p, q] : temp) {
            dp[x][1] = max(dp[x][1], 1 + sum - max(p, q) + p);
        }
    };

    dfs(dfs, 0, 0);

    cout << max(dp[0][0], dp[0][1]) << '\n';
}
