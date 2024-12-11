#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n; cin >> n;
    if(!n) {
        cout << 0 << '\n';
        return 0;
    }
    // 
    // | F(n)     |   | 1  1 | ^ n - 1    | F(n - 1) |
    // | F(n - 1) | = | 1  0 |         x  | F(n - 2) |
    //
    int mod = 1e9 + 7;    
    auto multiply = [&]( vector<vector<int>> a, vector<vector<int>> b) -> vector<vector<int>> {
        vector<vector<int>> ans(2, vector<int> (2));
        ans[0][0] = (1LL * a[0][0] * b[0][0] % mod + 1LL * a[0][1] * b[1][0] % mod) % mod;
        ans[0][1] = (1LL * a[0][0] * b[0][1] % mod + 1LL * a[0][1] * b[1][1] % mod) % mod;
        ans[1][0] = (1LL * a[1][0] * b[0][0] % mod + 1LL * a[1][1] * b[1][0] % mod) % mod;
        ans[1][1] = (1LL * a[1][0] * b[0][1] % mod + 1LL * a[1][1] * b[1][1] % mod) % mod;
        return ans;
    };

    auto power = [&](vector<vector<int>> a, long long y) -> vector<vector<int>> {
        vector<vector<int>> ans = { { 1, 0 }, { 0, 1 } };
        for(; y ; y >>= 1) {
            if (y & 1) {
                ans = multiply(ans, a);
            }
            a = multiply(a, a);
        }
        return ans;
    };

    vector<vector<int>> a = { { 1, 1 }, { 1, 0 } };

    auto ans = power(a, n - 1);

    cout << ans[0][0] << '\n';
}
