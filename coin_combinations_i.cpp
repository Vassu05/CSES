#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    int mod = 1e9 + 7;
    for(int &i : a) cin >> i;
    vector<int> dp(x + 1);
    dp[0] = 1;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < n; j++) {
            int ni = i + a[j];
            if(ni <= x) {
                dp[ni] = (dp[ni] + dp[i]) % mod;
            }
        }
    }
    cout << dp[x] << '\n';
}
