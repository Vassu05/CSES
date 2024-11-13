#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n; cin >> n;
    vector<vector<int>> a;
    for(int i = 0; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        a.push_back( { x, i + 1, z } );
        a.push_back( { y, - i - 1, z } );
    }
    sort(a.begin(), a.end(), [&](auto x, auto y) {
            if(x[0] == y[0]) return x[1] > y[1];
            else return x[0] < y[0];
    });
    int ans = 0;
    vector<int> dp(n + 1);
    for(auto it : a) {
        if(it[1] > 0) {
            dp[it[1]] = ans + it[2];
        }
        else {
            ans = max(ans, dp[-it[1]]);
        }
    }
    cout << ans << '\n';
}
