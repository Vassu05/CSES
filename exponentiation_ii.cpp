#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    while(n--) {
        int x, y, z; cin >> x >> y >> z;
        // fermat's little theorem: a ^ (p - 1) % p = 1
        auto power = [&](int x, int y, int mod) {
            int ans = 1;
            for(; y ; y >>= 1, x = 1LL * x * x % mod) if(y & 1) ans = 1LL * ans * x % mod;
            return ans;
        };
        cout << power(x, power(y, z, 1e9 + 7 - 1), 1e9 + 7) << '\n';
    }
}
