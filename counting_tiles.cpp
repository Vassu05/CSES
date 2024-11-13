#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;

    vector<vector<int>> collect(1 << n);

    auto isPossible = [&](int x, int y) -> bool {
        int now = x;
        for(int j = 0; j < n; j++) if(y >> j & 1) {
            if(now >> j & 1) return false;
            now |= (1 << j);
        }
        for(int j = 0; j < n - 1; j++) {
            if(!(now >> j & 1) && !(now >> (j + 1) & 1)) {
                now |= (1 << j);
                now |= (1 << (j + 1));
            }
        }
        return now == (1 << n) - 1;
    };

    for(int i = 0; i < 1 << n; i++) for(int j = 0; j < 1 << n; j++) {
        if(isPossible(i, j)) collect[i].push_back(j);
    }
    int mod = 1e9 + 7;

    vector<int> dp(1 << n);
    dp[0] = 1;

    for(int i = 0; i < m; i++) {
        vector<int> ndp(1 << n);
        for(int j = 0; j < 1 << n; j++) {
            for(auto it : collect[j]) {
                ndp[it] = (ndp[it] + dp[j]) % mod;
            }
        }
        dp = ndp;
    }


    cout << dp[0] << '\n';
}
