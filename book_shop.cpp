#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x; cin >> n >> x;
    vector<int> h(n), s(n);
    for(int &i : h) cin >> i;
    for(int &i : s) cin >> i;
    vector<int> dp(x + 1);
    for(int i = 0; i < n; i++) {
        for(int j = x - 1; j >= 0; j--) {
            int nj = j + h[i];
            if(nj <= x) dp[nj] = max(dp[nj], dp[j] + s[i]);
        }
    }
    cout << dp[x] << '\n';
}
