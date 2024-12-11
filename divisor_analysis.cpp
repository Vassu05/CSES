#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int mod = 1e9 + 7;

    auto power = [&](int x, int y) -> int {
        int ans = 1;
        for(; y ; y >>= 1, x = 1LL * x * x % mod) if(y & 1) ans = 1LL * ans * x % mod;
        return ans;
    };

    int a = 1, b = 1, c = 1;
    int temp = 1;

    for(int i = 1; i <= n; i++) {
        int x, k; cin >> x >> k;
        a = 1LL * a * (k + 1) % mod;
        int sum = 1LL * (power(x, k + 1) + mod - 1) * power(x - 1, mod - 2) % mod;
        b = 1LL * b * sum % mod;
        int pro = 1LL * power(x, 1LL * k * (k + 1) / 2 % (mod - 1));
        c = 1LL * power(c, k + 1) * power(pro, temp) % mod;
        temp = 1LL * temp * (k + 1) % (mod - 1);
    }

    cout << a << ' ' << b << ' ' << c;
}
