#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n); for(int &i : a) cin >> i;
    vector<pair<int,int>> dp((1 << n), { n + 1, x + 1 });
    dp[0] = { 0, x + 1 };
    for(int i = 0; i < 1 << n; i++) {
        for(int j = 0; j < n; j++) if(i >> j & 1) {
            int nj = i ^ (1 << j);
            if(dp[nj].second + a[j] > x) dp[i] = min(dp[i], make_pair(dp[nj].first + 1, a[j]));
            else dp[i] = min(dp[i], make_pair(dp[nj].first, dp[nj].second + a[j]));
        }
    }
    cout << dp.back().first << '\n';
}
