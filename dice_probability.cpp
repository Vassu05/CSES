#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, a, b; cin >> n >> a >> b;
    vector<double> dp(b + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        vector<double> ndp(b + 1, 0);
        for(int j = 0; j <= b; j++) {
            for(int k = max(0, j - 6); k < j; k++) {
                ndp[j] += dp[k] / 6;
            }
        }
        dp = ndp;
    }
    double ans = 0;
    for(int i = a; i <= b; i++) ans += dp[i];
    cout << fixed << setprecision(6) << ans << '\n';
}
