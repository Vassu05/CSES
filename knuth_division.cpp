#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e17;

int32_t main(){
    int n; cin >> n;
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        pre[i] = pre[i - 1] + x;
    }

    // check if a <= b <= c <= b are quadrangle friendly?
    // optimal split for (i, j) <= optimal split for(i + 1, k) where j <= k <= n
    vector<vector<int>> opt(n + 1, vector<int> (n + 1, n + 1));
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, inf));
    for(int i = 1; i <= n; i++) {
        opt[i][i] = i;
        dp[i][i] = 0;
    }

    for(int i = n - 1; i >= 1; i--) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = opt[i][j - 1]; k <= min(j - 1, opt[i + 1][j]); k++) {
                int curr = dp[i][k] + dp[k + 1][j] + pre[j] - pre[i - 1];
                if(dp[i][j] > curr) {
                    dp[i][j] = curr;
                    opt[i][j] = k;
                }
            }
        }
    }

    cout << dp[1][n] << '\n';
}
