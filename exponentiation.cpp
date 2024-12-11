#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    while(n--) {
        int x, y; cin >> x >> y;
        int ans = 1, mod = 1e9 + 7;
        for(; y ; y >>= 1, x = 1LL * x * x % mod) if(y & 1) ans = 1LL * ans * x % mod;
        cout << ans << '\n';
    }
}
