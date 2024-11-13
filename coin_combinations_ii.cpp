#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n); for(int &i : a) cin >> i;
    int mod = 1e9 + 7;
    vector<int> dp(x + 1);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < x; j++) {
            int nj = j + a[i];
            if(nj <= x) dp[nj] = (dp[nj] + dp[j]) % mod;
        }
    }
    cout << dp[x] << '\n';
}
