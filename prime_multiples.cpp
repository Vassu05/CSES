#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n; cin >> n;
    int k; cin >> k;
    vector<long long> temp(k);
    for(int i = 0; i < k; i++) cin >> temp[i];

    long long ans = 0;

    for(int i = 1; i < (1 << k); i++) {
        long long now = 0;
        for(int j = 0; j < k; j++) if(i >> j & 1) { 
            if(now == 0) {
                now = temp[j];
                continue;
            }
            long long g = gcd(now, temp[j]);
            now /= g;
            if(now > 2e18 / temp[j]) {
                now = 2e18 + 10;
            }
            else now *= temp[j];
        }
        int cnt = __builtin_popcount(i);
        if(cnt & 1) {
            ans += n / now;
        }
        else {
            ans -= n / now;
        }
    }

    cout << ans << '\n';
}
