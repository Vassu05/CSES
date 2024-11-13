#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int ans = 1, x = 2, mod = 1e9 + 7;
    while(n) {
        if (n & 1) ans = 1LL * ans * x % mod;
        n /= 2;
        x = 1LL * x * x % mod;
    }
    cout << ans << '\n';
}
