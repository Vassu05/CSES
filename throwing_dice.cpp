#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n; cin >> n;
    int mod = 1e9 + 7;

    vector<int> dp(7);
    dp[0] = 1;
    for(int i = 1; i <= 6; i++) {
        int sum = 0;
        for(int j = 0; j < i; j++) sum = (sum + dp[j]) % mod;
        dp[i] = sum;
    }
    // similar to fibonacci numbers but
    // F(n) = F(n - 1) + F(n - 2) + F(n - 3) + F(n - 4) + F(n - 5) + F(n - 6)
    auto multiply = [&]( vector<vector<int>> a, vector<vector<int>> b) -> vector<vector<int>>  {
        vector<vector<int>> ans(6, vector<int> (6));
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                for(int k = 0; k < 6; k++) {
                    ans[i][j] = (ans[i][j] + 1LL * a[i][k] * b[k][j] % mod) % mod;
                }
            }
        }
        return ans;
    };

    auto power = [&]( vector<vector<int>> a, long long y) -> vector<vector<int>> {
        vector<vector<int>> ans(6, vector<int> (6));
        for(int i = 0; i < 6; i++) ans[i][i] = 1;
        for(; y ; y >>= 1) {
            if(y & 1) ans = multiply(ans, a);
            a = multiply(a, a);
        }
        return ans;
    };

    if(n <= 6) {
        cout << dp[n] << '\n';
        return 0;
    }

    vector<vector<int>> a(6, vector<int> (6));
    for(int i = 0; i < 6; i++) a[0][i] = 1;
    for(int i = 1; i < 6; i++) a[i][i - 1] = 1;

    auto ans = power(a, n - 6);

    int res = 0;

    for(int i = 0; i < 6; i++) {
        res = (res + 1LL * ans[0][i] * dp[6 - i] % mod) % mod;
    }
    cout << res << '\n';
}
