#include <bits/stdc++.h>
using namespace std;
int main(){
    int mod = 1e9 + 7;

    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n, vector<int> (n));
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x][y] += 1;
    }

    auto multiply = [&]( vector<vector<int>> a, vector<vector<int>> b) -> vector<vector<int>> {
        vector<vector<int>> ans(n, vector<int> (n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int temp = 0; temp < n; temp++) {
                    ans[i][j] = (ans[i][j] + 1LL * a[i][temp] * b[temp][j] % mod) % mod;
                }
            }
        }
        return ans;
    };

    auto power = [&](vector<vector<int>> a, int y) -> vector<vector<int>> {
        vector<vector<int>> ans(n, vector<int> (n));
        for(int i = 0; i < n; i++) ans[i][i] = 1;
        for(; y ; y >>= 1, a = multiply(a, a)) if(y & 1) ans = multiply(ans, a);
        return ans;
    };

    auto ans = power(g, k);

    cout << ans[0][n - 1] << '\n';
}
