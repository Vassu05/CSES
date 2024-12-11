#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    int N = n + m - 1;
    int M = n - 1;

    int mod = 1e9 + 7;
    auto power = [&](int x, int y) -> int {
        int ans = 1;
        for(; y ; y >>= 1, x = 1LL * x * x % mod) if(y & 1) ans = 1LL * ans * x % mod;
        return ans;
    };

    // Find out N choose M
    int ans = 1;
    for(int i = N; i >= N - M + 1; i--) {
        ans = 1LL * ans * i % mod;
    }
    for(int i = 1; i <= M; i++) {
        ans = 1LL * ans * power(i, mod - 2) % mod;
    }
    cout << ans << '\n';
}
