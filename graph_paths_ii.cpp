#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int mod = 1e9 + 7;
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n, vector<int> (n, 2e18));
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        int c; cin >> c;
        --x, --y;
        g[x][y] = min(g[x][y], c);
    }

    auto multiply = [&]( vector<vector<int>> a, vector<vector<int>> b) -> vector<vector<int>> {
        vector<vector<int>> ans(n, vector<int> (n, 2e18));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int temp = 0; temp < n; temp++) {
                    ans[i][j] = min(ans[i][j], a[i][temp] + b[temp][j]);
                }
            }
        }
        return ans;
    };

    auto power = [&]( vector<vector<int>> a, int y) -> vector<vector<int>> {
        vector<vector<int>> ans(n, vector<int> (n, 2e18));
        for(int i = 0; i < n; i++) ans[i][i] = 0;
        for(; y ; y >>= 1, a = multiply(a, a)) if(y & 1) ans = multiply(ans, a);
        return ans;
    };

    auto ans = power(g, k)[0][n - 1];

    cout << (ans > 1e18 ? -1 : ans) << '\n';

}
