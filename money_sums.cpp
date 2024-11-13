#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;
    const int m = n * 1000;
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = m - 1; j >= 0; j--) {
            int nj = j + a[i];
            if(nj <= m) dp[nj] |= dp[j];
        }
    }
    cout << accumulate(dp.begin(), dp.end(), 0) - 1 << '\n';
    for(int i = 1; i <= m; i++) if(dp[i]) cout << i << ' ';
    cout << '\n';
}
