#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int mod = 1e9 + 7;
    auto power = [&](int x, long long y) -> int {
        int ans = 1;
        for(; y ; y >>= 1, x = 1LL * x * x % mod) if(y & 1) ans = 1LL * ans * x % mod;
        return ans;
    };
    if (n % 2 == 0) {
        // rotate by 0
        int ans = power(2, 1LL * n * n);
        // rotate by 90
        ans = (ans + power(2, 1LL * n * n / 4)) % mod;
        // rotate by 180
        ans = (ans + power(2, 1LL * n * n / 2)) % mod;
        // rotate by 270
        ans = (ans + power(2, 1LL * n * n / 4)) % mod;

        cout << 1LL * ans * power(4, mod - 2) % mod << '\n';
    }
    else {
        // rotate by 0
        int ans = power(2, 1LL * n * n);
        // rotate by 90
        ans = (ans + power(2, (1LL * n * n - 1) / 4 + 1)) % mod;
        // rotate by 180
        ans = (ans + power(2, (1LL * n * n - 1) / 2 + 1)) % mod;
        // rotate by 270
        ans = (ans + power(2, (1LL * n * n - 1) / 4 + 1)) % mod;

        cout << 1LL * ans * power(4, mod - 2) % mod << '\n';
    }
    // https://www.youtube.com/watch?v=drJN4O7tX5s&list=PLqf9emQRQrnIuv_U38k2jZyKStybMICTL
}
