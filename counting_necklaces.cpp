#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    int mod = 1e9 + 7;
    // burnside lemma
    auto power = [&](int x, int y) -> int {
        int ans = 1;
        for(; y ; y >>= 1, x = 1LL * x * x % mod) if(y & 1) ans = 1LL * ans * x % mod;
        return ans;
    };
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int g = gcd(i, n);
        ans = (ans + power(m, g)) % mod;
    }
    cout << 1LL * ans * power(n, mod - 2) % mod << '\n';

    // The idea is to count for each rotation the number of same structures that you can obtain before and after rotation
}
