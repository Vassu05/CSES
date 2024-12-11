#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n; cin >> n;
    int ans = 0, mod = 1e9 + 7;

    auto power = [&](int x, int y) -> int {
        int res = 1;
        for(; y ; y >>= 1, x = 1LL * x * x % mod) if(y & 1) res = 1LL * res * x % mod;
        return res;
    };

    int inv = power(2, mod - 2);

    for(int i = 1; 1LL * i * i <= n; i++) {
        long long now = n / i;
        now %= mod;
        ans = (ans + now * (now + 1) % mod * inv % mod - 1LL * (i + 1) * i % mod * inv % mod + mod) % mod;
        ans = (ans + 1LL * i * (now - i + 1) % mod) % mod;
    }
    cout << ans << '\n';
}
