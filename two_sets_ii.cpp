#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int req = n * (n + 1) / 2;
    if(req & 1) {
        cout << 0 << '\n';
        return 0;
    }
    req /= 2;
    int mod = 1e9 + 7;

    auto inv = [&](int x, int y) -> int {
        int ans = 1;
        for(; y ; y >>= 1, x = 1LL * x * x % mod) if(y & 1) ans = 1LL * ans * x % mod;
        return ans;
    };

    vector<int> dp(req + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for (int j = req; j >= 0; j--) {
            int nj = j + i;
            if (nj <= req) dp[nj] = (dp[nj] + dp[j]) % mod;
        }
    }
    cout << 1LL * dp[req] * inv(2, mod - 2) % mod << '\n';
}
