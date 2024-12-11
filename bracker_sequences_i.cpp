#include <bits/stdc++.h>
using namespace std;
int main(){
    int mod = 1e9 + 7;
    auto power = [&](int x, int y) -> int {
        int ans = 1;
        for(; y ; y >>= 1, x = 1LL * x * x % mod) if(y & 1) ans = 1LL * ans * x % mod;
        return ans;
    };

    int n; cin >> n;
    if(n & 1) {
        cout << 0 << '\n';
        return 0;
    }
    n /= 2;
    // 1 / (n + 1) * (2 * n choose n)
    int ans = 1;
    for(int i = 2 * n; i >= 2 * n - n + 1; i--) {
        ans = 1LL * ans * i % mod;
    }
    for(int i = 1; i <= n; i++) {
        ans = 1LL * ans * power(i, mod - 2) % mod;
    }
    ans = 1LL * ans * power(n + 1, mod - 2) % mod;
    cout << ans << '\n';
}
