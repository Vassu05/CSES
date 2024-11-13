#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n; cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    vector<vector<int>> dp(n + 2, vector<int> (n + 2, -1e17));
    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j < i; j++) dp[i][j] = 0;
    }
    for(int i = n; i >= 1; i--) {
        for(int j = i; j <= n; j++) {
            dp[i][j] = max({dp[i][j], a[i] + pre[j] - pre[i] - dp[i + 1][j], a[j] + pre[j - 1] - pre[i - 1] - dp[i][j - 1]});
        }
    }
    cout << dp[1][n] << '\n';
}
